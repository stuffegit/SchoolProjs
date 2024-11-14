/**
 * @file main.c
 * @author Christoffer Sundström
 * @date 7 November 2024
 * @brief Checks and validates Swedish personal identity numbers.
 *
 * 1. Prompts the user to enter a Swedish personal identity number.
 * 2. Validates the input for syntactical errors using the valdiate_input_format function.
 * 3. If the input fails validation, prompts the user to try again. If it passes, proceeds.
 * 4. Calculates the expected control digit value using the luhn_algorithm function.
 * 5. Compares the calculated control digit with the provided control digit and outputs the result.
 *
 * @see https://sv.wikipedia.org/wiki/Personnummer_i_Sverige Reference for algorithm help and logical guidance.
 * @see https://www.datorproblem.org/Personnummergenerator
 * @see https://simplycalc.com/luhn-calculate.php Tools to check program accuracy.
 **/
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define DASH_POSITION 6
#define YEAR_THRESHOLD 25
#define MIN_YEAR 1900
#define MAX_YEAR 9999
#define MIN_MONTH 1
#define MAX_MONTH 12
#define FEBRUARY 1
#define LEAP_YEAR_DAY_COUNT 29

int valdiate_input_format(char* input, int length);
int validate_date(int year, int month, int day);
int is_leap_year(int year);
int luhn_algorithm(char* input, int length);

int main(void) {
  int validinput = 0;   // Will be used as a checker for the while look in main.
  char input[12];       // The raw input from user.
  char digits_only[11]; // After removing the dash character.
  int length;

  while (!validinput) {
    (void)printf("Enter the number (format: YYMMDD-XXXX): ");
    scanf("%11s", input); // input will include the dash, we remove that later.
    length = strlen(input);

    validinput = valdiate_input_format(input, length); // check format: YYMMDD-xxxC.
  }

  int digit_character_position = 0;
  for (int i = 0; i < length; i++) { // Find and remove the dash from input to populate the digits_only string
    if (input[i] != '-') {
      digits_only[digit_character_position++] = input[i];
    }
  }
  digits_only[digit_character_position] = '\0'; // Null-terminate the digits_only string

  // Capture year, month, and day into variables to check validity
  int year = 0, month = 0, day = 0;
  sscanf(input, "%2d%2d%2d", &year, &month, &day);
  if (!validate_date(year, month, day)) {
    (void)printf("Date is out of range.\n");
    return TRUE;
  }

  // Gather result of luhn algorithm and the given control digit.
  int calculated_control_digit = (10 - (luhn_algorithm(digits_only, 9) % 10)) % 10;
  int provided_control_digit = digits_only[9] - '0';

  // Final comparison.
  if (calculated_control_digit == provided_control_digit) {
    (void)printf("The personalnumber is correct.\n");
  } else {
    (void)printf("The personalnumber is not valid.\n");
  }
  return FALSE;
}

/**
 * @brief Validates the format of the Swedish personal identity number.
 *
 * This function checks if the input follows the format YYMMDD-XXXX.
 * It ensures the correct number of digits and that the dash is in the correct position.
 *
 * @param input The user-entered personal number as a string.
 * @param length The length of the input string.
 * @return 1 if the format is valid, 0 otherwise.
 */
int valdiate_input_format(char* input, int length) {
  int result;
  // Check length of input, check the dash, and make sure everything is a digit
  // Correct input will break the whileloop in the main function
  char check_first_part[7], check_second_part[5];
  if (length != 11 || sscanf(input, "%6[0-9]-%4[0-9]", check_first_part, check_second_part) != 2) {
    (void)printf("Invalid format.\n");
    result = FALSE;
  } else {
    result = TRUE;
  }
  return result;
}

/**
 * @brief Checks if a date is valid based on year, month, and day.
 *
 * This function adjusts the year based on the YEAR_THRESHOLD to handle two-digit years
 * and verifies the day of the month, respecting leap years for February.
 *
 * @param year The two-digit year.
 * @param month The month (1–12).
 * @param day The day of the month (1–31 depending on the month).
 * @return 1 if the date is valid, 0 otherwise.
 */
int validate_date(int year, int month, int day) {
  int is_date_valid = TRUE;

  if (year < YEAR_THRESHOLD) {
    year += 2000;
  } else {
    year += 1900;
  }

  if (year < MIN_YEAR || year > MAX_YEAR) { // Check if year is in valid range
    is_date_valid = FALSE;
  }
  if (month < MIN_MONTH || month > MAX_MONTH) { // Check month validity
    is_date_valid = FALSE;
  }
  int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Check day validity based on month
  if (month == 2 && is_leap_year(year)) {
    days_in_month[FEBRUARY] = LEAP_YEAR_DAY_COUNT; // February in a leap year
  }
  if (day < 1 || day > days_in_month[month - 1]) { // -1 to correct index
    is_date_valid = FALSE;
  }
  return is_date_valid;
}

/**
 * @brief Determines if a year is a leap year.
 *
 * Uses the standard leap year rules to check if a given year has 366 days.
 *
 * @param year The year to check.
 * @return 1 if the year is a leap year, 0 otherwise.
 */
int is_leap_year(int year) {
  // This returns into the validate_date function
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**
 * @brief Calculates the Luhn checksum for a given number string.
 *
 * This function applies the Luhn algorithm to verify the control digit
 * of a personal identity number. The Luhn algorithm is commonly used for
 * validation of identification numbers.
 *
 * @param input The digit string (without dashes) for which to calculate the checksum.
 * @param length The length of the input string.
 * @return The computed Luhn checksum.
 * @see https://en.wikipedia.org/wiki/luhn_algorithm
 */
int luhn_algorithm(char* input, int length) {
  int alternate = TRUE;
  int sum = 0;
  int digit = 0;
  int double_digit = 0;

  for (int i = 0; i < length; i++) { // Loop through each char from the input
    // Convert char to an int.
    // https://www.geeksforgeeks.org/c-program-for-char-to-int-conversion/
    digit = input[i] - '0';

    if (alternate) { // multiply by 2 or 1, alternating with the alternate variable
      double_digit = digit * 2;
      if (double_digit > 9) { // If doubled result is > 9 making it two numbers we sum the digits
        double_digit = (double_digit / 10) + (double_digit % 10);
      }
      sum += double_digit;
    } else {
      sum += digit;
    }
    alternate = !alternate; // Swap around for next go in the loop
  }
  return sum;
}
