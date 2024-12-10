#include "filehandler.h"

int main(void) {
  user_t users[LEN];
  fill_users(users, LEN);
  write_users_to_file(users);
  read_users_from_file(users);
  add_user(users, "newboy");
  return 0;
}
