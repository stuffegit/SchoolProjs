#include <stdio.h>
#include <stdint.h>

#define EXPRESSION (3 * j / k - 2)
#define SET_VARIABLES \
{ \
i = 3; \
j = 2; \
k = 0; \
}

int main(void){
int i = 0, j = 7, k = 6;
char a = 'A', b = '3';
int32_t x, y = 3;
uint32_t z = 32;
double d;

x = EXPRESSION;
printf("A) %d\n", x);

y -= ((j << 1) & (k >> 1));
printf("B) %d\n", y);

x = (!(i && k) || !k) ? k + b : j + b;
printf("C) %d\n", x);

a += (b + k--) % 10;
printf("D) %d\n", a);

d = (double)j * 100 / --k / 3;
printf("E) %f\n", d);

x = -1;
y = (x < z) ? (k < j < 0) : (b >= a < i);
printf("F) %d\n", y);

d = x / z;
printf("G) %f\n", d);

i = 4;
j = -1;
k = 0;
x = i && j && k;
y = i || j && k;
printf("H) %d, %d\n", x, y);

x = i && j || k;
y = i || j || k;
printf("I) %d, %d\n", x, y);

SET_VARIABLES;
y = ++i || ++j && k++;
printf("J) %d, %d, %d, %d\n", i, j, k, y);

SET_VARIABLES;
y = (123 && --i) ? k++ : ++k;
printf("K) %d, %d, %d, %d\n", i, j, k, y);

SET_VARIABLES;
y = ++i && ++j && k++;
printf("L) %d, %d, %d, %d\n", i, j, k, y);

i = 4;
j = --i;
k = i--;
printf("M) %d, %d, %d\n", i, j, k);

i = -1;
j = 1;
i && printf("N) Hello World!\n") && --j;

++i && j && printf("O) Hello World!\n");
i || printf("P) Hello World!\n") || j++;

j-- || !printf("Q) Hello World!\n") || i++;

printf("R) %d, %d\n", i, j);

return 0;
}
