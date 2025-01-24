/**
 * @file    main.c
 * @author  Christoffer Sundström
 * @date    05 December 2024
 * @brief   Handles a database of users in a
 *          binary file called "users.bin".
 *
 * @desc    This main.c file holds all meta functionalities
 *          like handling the programloop and inputs.
 *
 *          file.c will have functions that interact with the file.
 *
 *          Supports following features:
 *          - Printing out the database.
 *          - Creating a new user.
 *          - Updating an existing user.
 *          - Deleting an existing user.
 *
 *          Supported keypresses are C, P, U, D, E(and Q).
 *
 **/
#include "file.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {

  // Make sure old data does not leak into new process.
  // This should be deleted on Exit, but we dont trust software to exit gracefully.
  remove(FILENAME);

  current_id = 0; // Initialize current_id.

  int shouldrun = 1;

  // Main programloop which holds all functionality.
  // The "shouldrun" variable is only altered in the Exit if-case.
  while (shouldrun) {

    char choice = get_valid_choice(); // Returns upper case only.

    // Create a user:
    if (choice == 'C') {
      user_t new_user;
      new_user.age = 0; // Make sure old values never leak over.
      printf("Enter new user name (20 characters max):\n");
      scanf("%19s", new_user.name);

      // Capitalize first letter.
      new_user.name[0] = toupper(new_user.name[0]);

      // Make sure no other letters are capitalized.
      for (int i = 1; i < 19; i++) {
        new_user.name[i] = tolower(new_user.name[i]);
      }

      printf("Enter age:\n");
      scanf("%d", &new_user.age);
      clear_input_buffer();
      if (!new_user.age) {
        printf("This user can't be created\nAge is not valid.\n");
      } else if (!*new_user.name) {
        printf("This user can't be created\nName is not valid.\n");
      } else {
        create_user(FILENAME, &new_user);
      }

      // Print users:
    } else if (choice == 'P') {
      print_users(FILENAME);

      // Update a user:
    } else if (choice == 'U') {
      user_t new_user;
      printf("Enter ID to change: ");
      int update_id;
      scanf("%d", &update_id);
      clear_input_buffer();
      printf("Enter new name: ");
      char update_name[USER_T_NAMESIZE];
      scanf("%19s", update_name);
      clear_input_buffer();
      strncpy(new_user.name, update_name, sizeof(new_user.name));
      printf("Enter age: ");
      int update_age;
      scanf("%d", &update_age);
      clear_input_buffer();
      new_user.age = update_age;
      new_user.id = update_id;
      update_user(FILENAME, &new_user);

      // Delete a user:
    } else if (choice == 'D') {
      printf("Enter ID to delete: ");
      int delete_id;
      scanf("%d", &delete_id);
      clear_input_buffer();
      delete_user(FILENAME, delete_id);

      // Exit:
    } else if (choice == 'E' || choice == 'Q') { // Easteregg, Q also works.
      shouldrun = 0;

      // Clean up.
      remove(FILENAME);

      // Incorrect-Syntax Error Handling:
    } else {
      printf("%c is an invalid option!\n", choice);
    }
  }
  return 0;
}
