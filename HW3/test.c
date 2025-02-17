/* Print a float in binary: ftob.c */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//void float_to_string(float f, char *s, int n);
void float_to_string(float,char *,int);
void print_float();

#define LEN 32
#define EXP_32 8		/* ending index of s for exponent */
#define MAN_32 9		/* starting index of s for significand */

int main(int argc, char **argv) {
  int n=LEN;
  float f;
  char s[LEN];

  f = atof(argv[1]);
  printf("f=%f\n",f);

  float_to_string(f,s,n);
  print_float(s,n);

  return 0;
}
void float_to_string(float f, char *s, int n) {
    unsigned int u_int = *((unsigned int *)&f);
    for (int i = n - 1; i >= 0; i--) {
        s[i] = (u_int & 1) ? '1' : '0';
        u_int >>= 1;
    }
    s[n] = '\0';
}
void print_float(char *s, int n) {
    printf("%c ", s[0]);

    for (int i = 1; i < n; i++) {
        if (i == EXP_32) {
            printf(" ");
        }
        printf("%c", s[i]);
    }
    printf("\n");
}