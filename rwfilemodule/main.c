#include "filehandler.h"

#define LEN 3

int main(void) {
  user_t users[LEN];
  fill_users(users, LEN);
  print_users(users);
  write_users_to_file(users);
  read_users_from_file(users);
  change_users_name(users, 2);
  read_users_from_file(users);
  return 0;
}
