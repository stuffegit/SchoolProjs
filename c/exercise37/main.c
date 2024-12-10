#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* split_string(const char* str, const char delim);

int main(int argc, char* argv[]) {
  char* str = argv[1];
  char* pch;
  pch = split_string(str, ' ');
  while (pch != NULL) {
    printf("%s\n", pch);
    free(pch);
    pch = split_string(NULL, ' ');
  }
  return 0;
}

static char* split_string(const char* str, const char delim) {
  static const char* curr_pos; // save current position
  if (str != NULL) {
    if (*str == '\0') { // if empty string
      printf("str empty\n");
      return NULL;
    }
    curr_pos = str; // start at the beginning of the new string
    printf("split_string(\"%s\"):\n", str);
  }
  if (*curr_pos == '\0') { // end of string = return null
    return NULL;
  }

  const char* start = curr_pos;                     // declare start of token
  while (*curr_pos != '\0' && *curr_pos != delim) { // find delimiter
    curr_pos++;
  }

  int token_length = curr_pos - start;    // determine len til next delim
  char* token = malloc(token_length + 1); // +1 for '\0'
  if (token == NULL) {                    // Check if malloc failed
    printf("malloc fail\n");
    return NULL;
  }
  strncpy(token, start, token_length); // copies until next delim
  token[token_length] = '\0';          // null the string ending

  if (*curr_pos == delim) {
    curr_pos++; // skip delimiter
  }

  return token;
}
