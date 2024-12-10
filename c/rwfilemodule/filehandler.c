#include "filehandler.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// names for the fill func
const char* firstNames[] = {"Alice", "Bob", "Charlie"};
const char* middleNames[] = {"John", "Michael", "David"};
const char* lastNames[] = {"Smith", "Jones", "Brown"};

void fill_users(user_t* users, int amount) {
  srand(time(NULL));
  for (int i = 0; i < amount; i++) {
    snprintf(users[i].name, MAX_NAME_LENGTH, "%s %s %s", firstNames[rand() % 3],
             middleNames[rand() % 3], lastNames[rand() % 3]);
    users[i].unique_id = i + 1;
  }
}

void print_users(const user_t* users) {
  printf("- print_users();\n");
  for (int i = 0; i < LEN; i++) {
    printf("UserID %d: %s\n", users[i].unique_id, users[i].name);
  }
}

void write_users_to_file(const user_t* users) {
  FILE* file = fopen("users.bin", "wb"); // define filename and mode for the file pointer
  assert(file);
  fwrite(users, sizeof(user_t), LEN, file); // write the entire array of users
  fclose(file);
}

void read_users_from_file(user_t* users) {
  FILE* file = fopen("users.bin", "rb"); // define filename and mode for the file pointer
  assert(file);
  int usr = 0;
  while ((users + usr)->unique_id == usr + 1) {
    usr++;
  }
  fread(users, sizeof(user_t), usr, file); // read the entire array of users
  for (int i = 0; i < usr; i++) {
    printf("UserID %d: %s\n", users[i].unique_id, users[i].name);
  }
  fclose(file);
}

void change_users_name(user_t* users, int tar_id) {
  FILE* file = fopen("users.bin",
                     "rb+"); // define filename and mode for the file pointer
  assert(file);
  for (int i = 0; i < LEN; i++) {
    if (users[i].unique_id == tar_id) {
      snprintf(users[i].name, MAX_NAME_LENGTH,
               "New Name"); // snprintf to write to sized buffer
      fseek(file, sizeof(user_t) * i,
            SEEK_SET); // move to position of the userID in the file
      fwrite(&users[i], sizeof(user_t), 1,
             file); // write2file - buffer, size, count, stream
      break;
    }
  }
  fclose(file);
}

void add_user(user_t* users, char* name) {
  // define filename and mode for the file pointer
  FILE* file = fopen("users.bin", "rb");
  assert(file);

  fseek(file, 0, SEEK_SET);

  int lines = 1;
  int ch;
  while ((ch = fgetc(file)) != EOF) {
    if (ch) {
      lines++;
    }
  }

  printf("%d\n", lines);

  // fprintf(file, "UserID %d: %s\n", lines, name);
  read_users_from_file(users);
  fclose(file);
}
