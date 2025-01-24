/**
 * @file    file.h
 * @author  Christoffer Sundström
 * @date    05 December 2024
 * @brief   Declared functions will be defined
 *          in file.c and used in main.c
 *
 **/
#ifndef FILE_H
#define FILE_H

#define USER_T_NAMESIZE 20
#define FILENAME "users.bin"
#define TEMPFILENAME "temp.bin"

typedef struct {
  int id;
  int age;
  char name[USER_T_NAMESIZE];
} user_t;

extern int current_id;
/**
 * Clears the input buffer to avoid overflowing into next scan.
 **/
void clear_input_buffer();

/**
 * Presents and handles inputs from user. Capitalizes the choice.
 **/
char get_valid_choice();

/**
 * Allows creation of user and definition of user name and age.
 * Automatically increments the ID.
 **/
int create_user(const char* filename, const user_t* user);

/**
 * Allows modification of an existing user name and age.
 * Unique ID stays.
 **/
int update_user(const char* filename, const user_t* user);

/**
 * Handles deletion of a specific user.
 * ID is not reused.
 **/
int delete_user(const char* filename, int id);

/**
 * Prints the contents of the user database in a formatted manner.
 **/
void print_users(const char* filename);

#endif // FILE_H
