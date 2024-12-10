#ifndef FILE_H
#define FILE_H

typedef struct {
  int id;
  char name[50];
} user_t;

extern int current_id;

void clear_input_buffer();
int get_valid_choice();
int add_user(const char* filename, const user_t* user);
int update_user(const char* filename, const user_t* user);
int delete_user(const char* filename, int id);
void print_users(const char* filename);

#endif // FILE_H
