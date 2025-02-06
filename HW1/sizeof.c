#include <stdio.h>

int main(){
    int i = 1;
    float f = 2.0;
    char c = 'A';
    short s = 4;
    long l = 1;
    double d = 1;
    long double ld = 1;
    char *ptr = &c;

    printf("size of char - %d\n", sizeof(c));
    printf("size of short - %d\n", sizeof(s));
    printf("size of int - %d\n", sizeof(i));
    printf("size of long - %d\n", sizeof(l));
    printf("size of float - %d\n", sizeof(f));
    printf("size of double - %d\n", sizeof(d));
    printf("size of long double - %d\n", sizeof(ld));
    printf("size of pointer - %d\n", sizeof(ptr));
}