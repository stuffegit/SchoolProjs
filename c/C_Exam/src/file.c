#include "file.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define FAIL -1
#define SUCCESS 0

int current_id = 0;

/**
 * Clears the input buffer to avoid overflowing into next scan.
 **/
void clear_input_buffer() {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF) {
    // Nothing is done here, we just let the while-loop run.
  }
}

/**
 * Presents and handles inputs from user. Capitalizes the choice.
 **/
char get_valid_choice() {
  char input[10];
  char choice;

  while (1) { // Will only respect "break;" to stop.

    // Draw graphics
    for (int i = 0; i < 9; i++) {
      printf("=");
    }
    printf("DB");
    for (int i = 0; i < 10; i++) {
      printf("=");
    }

    // List choices handled in the while-loop in main();
    printf("\nC) Create A Student");
    printf("\nP) Print All Students");
    printf("\nU) Update A Student");
    printf("\nD) Delete A Student");
    printf("\nE) Exit");
    printf("\nChoose an option: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
      if (sscanf(input, "%c", &choice) == 1) {
        choice = toupper(choice);
        system("clear");
        break;
      }
    }
    clear_input_buffer();
  }
  return choice;
}

/**
 * Allows creation of user and definition of user name and age.
 * Automatically increments the ID.
 **/
int create_user(const char* filename, const user_t* user) {
  FILE* file = fopen(filename, "ab");
  int result = FAIL;

  if (file) {
    user_t new_user = *user;
    new_user.id = ++current_id;

    fwrite(&new_user, sizeof(user_t), 1, file);
    fclose(file);
    system("clear");
    result = SUCCESS;
  }

  return result;
}

/**
 * Allows modification of an existing user name and age.
 * Unique ID stays.
 **/
int update_user(const char* filename, const user_t* user) {
  FILE* file = fopen(filename, "r+b");
  int result = FAIL;

  if (file) {
    user_t temp;
    while (fread(&temp, sizeof(user_t), 1, file)) {
      if (temp.id == user->id) {
        fseek(file, -sizeof(user_t), SEEK_CUR);
        fwrite(user, sizeof(user_t), 1, file);
        result = SUCCESS;
        break;
      } else {
        system("clear");
        printf("User does not exist at index.\n");
      }
    }
    fclose(file);
  }

  return result;
}

/**
 * Handles deletion of a specific user.
 * ID is not reused.
 **/
int delete_user(const char* filename, int id) {
  FILE* file = fopen(filename, "rb");
  FILE* temp_file = fopen(TEMPFILENAME, "wb");
  int result = FAIL;

  if (file && temp_file) {
    user_t temp;
    int found = 0;
    while (fread(&temp, sizeof(user_t), 1, file)) {
      if (temp.id != id) {
        fwrite(&temp, sizeof(user_t), 1, temp_file);
      } else {
        found = 1;
      }
    }

    fclose(file);
    fclose(temp_file);

    if (found) {
      remove(filename);
      rename(TEMPFILENAME, filename);
      result = SUCCESS;
    } else {
      remove(TEMPFILENAME);
    }
  }

  return result;
}

/**
 * Prints the contents of the user database in a formatted manner.
 **/
void print_users(const char* filename) {
  FILE* file = fopen(filename, "rb");

  if (file) {
    user_t temp;
    printf("ID\tAge\tName\n");
    // Magicnumber for drawing graphics.
    for (int i = 0; i < 21; i++) {
      printf("=");
    }
    printf("\n");
    while (fread(&temp, sizeof(user_t), 1, file)) {
      printf("%d\t%d\t%s\n", temp.id, temp.age, temp.name);
    }
    printf("\n");
    fclose(file);
  }
}
