/**
 * @file main.c
 * @author Christoffer Sundström
 * @date 16 November 2024
 * @brief Encrypt CRC with check value then recheck validity at end.
 *
 * 1. Prompts the user to enter a message.
 * 2. Validates the input length.
 * 3. If the input fails validation, exit program.
 * 4. Generates the CRC value using the calculate_crc function on line 56 with the 0xC599 polynomial.
 * 5. Verifies the CRC value by re-calculating
 *
 * @see https://www.youtube.com/watch?v=izG7qT0EpBw - The main source that thought me CRCs.
 * @see https://en.wikipedia.org/wiki/Computation_of_cyclic_redundancy_checks - Logic help.
 **/
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define POLYNOMIAL 0xC599     // CRC-15 polynomial
#define CRC_BITS 15           // Number of bits in the CRC
#define MAX_MESSAGE_LENGTH 14 // Maximum allowed message length
#define BYTE_SIZE 8           // Number of bits in a byte

// Function declarations
uint16_t calculate_crc(const uint8_t* message, size_t length);       // Calculates CRC checksum
int verify_crc(const uint8_t* message, size_t length, uint16_t crc); // Verifies CRC checksum

int main() {
  int error = 0;
  char input[MAX_MESSAGE_LENGTH + 2]; // Input buffer for user message (+2 for newline and null terminator)
  printf("Enter a message (max %d characters): ", MAX_MESSAGE_LENGTH);
  fgets(input, sizeof(input), stdin); // Read input

  size_t length = strcspn(input, "\n"); // Remove the newline character that fgets love adding from stdin
  input[length] = '\0';                 // Null-terminate the string

  if (length > MAX_MESSAGE_LENGTH) {
    printf("Error: Message exceeds maximum length of %d characters.\n", MAX_MESSAGE_LENGTH);
    error = 1;
  } else {

    printf("Original message: %s", input);
    for (int i = 0; i < (sizeof(input) / sizeof(input[0])); i++) {
      if (*(input + i)) {
        printf("%08b", *(input + i));
      }
    }
    printf("\n");

    uint8_t message[length]; // Array to hold message as uint8_t
    for (size_t i = 0; i < length; i++) {
      message[i] = (uint8_t)input[i];
    } // Convert chars to uint8_t

    uint16_t crc = calculate_crc(message, length); // Encrypted message
    printf("CRC-15 encrypted message: %08b\n", crc);

    // Simulate "receiving" the message
    uint8_t received_message[length];
    memcpy(received_message, message, length);

    if (verify_crc(received_message, length, crc)) { // Check if CRC matches original message
      printf("Message is valid and intact!\nDecrypted message: ");
      for (size_t i = 0; i < length; i++) {
        printf("%c", received_message[i]);
      }
      printf("\n");
    } else {
      printf("Message is corrupted.\n");
    }
  }
  if (error) {
    printf("Program exited with errors\n");
  }
  return 0;
}

// Function definitions
uint16_t calculate_crc(const uint8_t* message, size_t length) {
  uint16_t crc = 0; // Initialize CRC to 0
  for (size_t i = 0; i < length; i++) {
    crc ^= message[i] << (CRC_BITS - BYTE_SIZE); // Align byte to the top of CRC
    for (int j = 0; j < BYTE_SIZE; j++) {        // Process each bit in the byte
      crc = (crc & (1 << (CRC_BITS - 1))) ? (crc << 1) ^ POLYNOMIAL : crc << 1;
    }
  }
  return crc & ((1 << CRC_BITS) - 1); // Mask to CRC size
}

int verify_crc(const uint8_t* message, size_t length, uint16_t crc) {
  return calculate_crc(message, length) == crc; // Return 1 if valid, 0 otherwise
}
