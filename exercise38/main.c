#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 3
#define MAX_NAME_LENGTH 100

// names for the fill func
const char* firstNames[] = {"Alice", "Bob", "Charlie"};
const char* middleNames[] = {"John", "Michael", "David"};
const char* lastNames[] = {"Smith", "Jones", "Brown"};

typedef struct {
  char name[MAX_NAME_LENGTH];
  int unique_id;
} user_t;

void fill_users(user_t* users, int amount);
void print_users(user_t* users);
void write_users_to_file(user_t* users);
void read_users_from_file(user_t* users);
void change_users_name(user_t* users, int tar_id);

int main(void) {
  srand(time(NULL));
  user_t users[LEN];
  fill_users(users, LEN);
  print_users(users);
  write_users_to_file(users);
  read_users_from_file(users);
  change_users_name(users, 2);
  read_users_from_file(users);
  return 0;
}

void fill_users(user_t* users, int amount) {
  printf("- fill_users();\n");
  for (int i = 0; i < amount; i++) {
    snprintf(users[i].name, MAX_NAME_LENGTH, "%s %s %s", firstNames[rand() % 3], middleNames[rand() % 3], lastNames[rand() % 3]);
    users[i].unique_id = i + 1;
  }
}

void print_users(user_t* users) {
  printf("- print_users();\n");
  for (int i = 0; i < LEN; i++) {
    printf("UserID %d: %s\n", users[i].unique_id, users[i].name);
  }
}

void write_users_to_file(user_t* users) {
  printf("- write_users_to_file();\n");
  FILE* file = fopen("users.bin", "wb"); // define filename and mode for the file pointer
  if (!file) {
    printf("Error opening or creating file in function write_users_to_file\n");
  }
  fwrite(users, sizeof(user_t), LEN, file); // write the entire array of users
  fclose(file);
}

void read_users_from_file(user_t* users) {
  printf("- read_users_from_file();\n");
  FILE* file = fopen("users.bin", "rb"); // define filename and mode for the file pointer
  if (!file) {
    printf("Error opening or creating file in function read_users_from_file\n");
  }
  fread(users, sizeof(user_t), LEN, file); // read the entire array of users
  for (int i = 0; i < LEN; i++) {
    printf("UserID %d: %s\n", users[i].unique_id, users[i].name);
  }
  fclose(file);
}

void change_users_name(user_t* users, int tar_id) {
  printf("- change_users_name();\n");
  FILE* file = fopen("users.bin", "rb+"); // define filename and mode for the file pointer
  if (!file) {
    printf("Error opening or creating file in function read_users_from_file\n");
  }
  for (int i = 0; i < LEN; i++) {
    if (users[i].unique_id == tar_id) {
      snprintf(users[i].name, MAX_NAME_LENGTH, "New Name"); // snprintf to write to sized buffer
      fseek(file, sizeof(user_t) * i, SEEK_SET);            // move to position of the userID in the file
      fwrite(&users[i], sizeof(user_t), 1, file);           // write2file - buffer, size, count, stream
      break;
    }
  }
  fclose(file);
}
