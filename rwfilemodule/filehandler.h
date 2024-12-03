#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#define MAX_NAME_LENGTH 100
#define LEN 3

typedef struct {
  char name[MAX_NAME_LENGTH];
  int unique_id;
} user_t;

void fill_users(user_t* users, int amount);
void print_users(const user_t* users);
void write_users_to_file(const user_t* users);
void read_users_from_file(user_t* users);
void add_user(user_t* users, char* name);
void change_users_name(user_t* users, int tar_id);
void delete_user(const user_t* users, int tar_id);

#endif // !FILEHANDLER_H
