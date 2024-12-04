#include "file.h"
#include <stdio.h>
#include <stdlib.h>

#define FAIL -1
#define SUCCESS 0

int current_id = 0;

void clear_input_buffer() {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF) {
    // clear input buffer
  }
}

int get_valid_choice() {
  char input[10];
  int choice = 0;
  while (1) {
    system("clear");
    print_users("users.bin");
    printf("\n1. Add User\n2. Read User file\n3. Change User\n4. Delete User\n5. Quit\nChoice: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
      if (sscanf(input, "%d", &choice) == 1 && choice >= 1 && choice <= 5) {
        break;
      } else {
        break;
      }
    }
    clear_input_buffer();
  }
  return choice;
}

int add_user(const char* filename, const user_t* user) {
  FILE* file = fopen(filename, "ab");
  int result = FAIL;

  if (file) {
    user_t new_user = *user;
    new_user.id = ++current_id;

    fwrite(&new_user, sizeof(user_t), 1, file);
    fclose(file);
    result = SUCCESS;
  }

  return result;
}

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
      }
    }
    fclose(file);
  }

  return result;
}

int delete_user(const char* filename, int id) {
  FILE* file = fopen(filename, "rb");
  FILE* temp_file = fopen("temp.bin", "wb");
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
      rename("temp.bin", filename);
      result = SUCCESS;
    } else {
      remove("temp.bin");
    }
  }

  return result;
}

void print_users(const char* filename) {
  FILE* file = fopen(filename, "rb");

  if (file) {
    user_t temp;
    while (fread(&temp, sizeof(user_t), 1, file)) {
      printf("ID: %d, Name: %s\n", temp.id, temp.name);
    }
    fclose(file);
  }
}
