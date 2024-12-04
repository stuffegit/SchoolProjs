#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define name array in main.c
const char* names[] = {"Alice", "Bob", "Carol", "Dave", "Eve"};

extern int current_id;

int main(void) {
  remove("users.bin");
  current_id = 0; // Initialize current_id

  user_t users[5];
  user_t new_user;
  for (int i = 0; i < 5; i++) {
    snprintf(users[i].name, sizeof(users[i].name), "%s", names[i % 5]);
    add_user("users.bin", &users[i]);
  }

  int shouldrun = 1;
  while (shouldrun) {
    print_users("users.bin");

    int choice = get_valid_choice();
    switch (choice) {
    case 1:
      printf("Enter new user name (20 characters max):\n");
      scanf("%19s", new_user.name);
      clear_input_buffer();
      add_user("users.bin", &new_user);
      break;
    case 2:
      // just repeat while-loop since it prints automatically.
      break;
    case 3:
      printf("Enter ID to change: ");
      int update_id;
      scanf("%d", &update_id);
      clear_input_buffer();
      printf("Enter new name: ");
      char update_name[50]; // Ensure size matches user_t
      scanf("%49s", update_name);
      clear_input_buffer();
      strncpy(new_user.name, update_name, sizeof(new_user.name));
      new_user.id = update_id;
      update_user("users.bin", &new_user);
      break;
    case 4:
      printf("Enter ID to delete: ");
      int delete_id;
      scanf("%d", &delete_id);
      clear_input_buffer();
      delete_user("users.bin", delete_id);
      break;
    case 5:
      shouldrun = 0;
      break;
    default:
      // Maybe some errorhandling but idk.
      break;
    }
    system("clear");
  }
  return 0;
}
