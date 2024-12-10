#include <stdio.h>
#include <stdlib.h>

#define SIZE 3
#define CONST 3

int choosefunc();
void display_matrix(int matrix[SIZE][SIZE]);
void multiply_constant(int matrix[SIZE][SIZE]);
void add_constant(int matrix[SIZE][SIZE]);
void transpose_matrix(int matrix[SIZE][SIZE]);

typedef void (*matrixoperation)(int matrix[SIZE][SIZE]);

int main(void) {
  int selection = 0;
  int matrix[SIZE][SIZE] = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};

  matrixoperation operations[] = {display_matrix, multiply_constant,
                                  add_constant, transpose_matrix};

  while (1) {
    selection = choosefunc();
    if (selection == 0) {
      system("clear");
    } else if (selection == 1) {
      operations[0](matrix);
    } else if (selection == 2) {
      operations[1](matrix);
    } else if (selection == 3) {
      operations[2](matrix);
    } else if (selection == 4) {
      operations[3](matrix);
    }
  }
  return 0;
}

int choosefunc() {
  int selection = 0;
  while (selection < 1 || selection > 4) {
    (void)printf(
        "1. Display Matrix\n2. Multiply with constant\n3. Add with "
        "constant\n4. Transpose Matrix\n0. Clear Terminal\nEnter selection: ");
    scanf(" %d", &selection);
    if (selection >= 0 && selection <= 4) {
      break;
    } else {
      printf("Wrong input, choose between: \n");
    }
  }
  return selection;
}

void display_matrix(int matrix[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int ii = 0; ii < SIZE; ii++) {
      (void)printf("%d ", matrix[ii][i]);
    }
    (void)printf("\n");
  }
  printf("\n");
}

void multiply_constant(int matrix[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int ii = 0; ii < SIZE; ii++) {
      matrix[ii][i] *= CONST;
    }
  }
}

void add_constant(int matrix[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int ii = 0; ii < SIZE; ii++) {
      matrix[ii][i] += CONST;
    }
  }
}

void transpose_matrix(int matrix[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = i + 1; j < SIZE; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
}
