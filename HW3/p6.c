#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Usage -> $ ./p6 0 01111110 10000000000000000000000
int main(int argc, char *argv[]){
    // v=(–1)^s * M * 2^E n: E=Exp–Bias(127)

    int sign, exponent = 0;
    float mantissa;

    int bias = 127;

    // sign var 0 or 1
    sign = atoi(argv[1]);

    int val = pow(2, 7);

    // calculate exponent value E = exp - bias
    for(int i = 0; i < strlen(argv[2]) - 1; i++){
        if (argv[2][i] == '1'){
            exponent += val;
        }
        val = val / 2;
    }

    if (exponent == 0){
        mantissa = 0.0;
        exponent = -126;
    } else {
        mantissa = 1.0;
        exponent = exponent - bias;
    }

    // calculate mantissa
    float val1 = 0.5;

    for(int i = 0; i < 23; i++){
        if (argv[3][i] == '1'){
            mantissa += val1;
        }
        val1 = val1 / 2;
    }

    float res = powf(-1, sign) * mantissa * powf(2, exponent);
    printf("f - %f\n", res);

    // concat string together and then use unsigned int pointer to convert to flaot
    char *binary;

    binary = argv[1];
    strcat(binary, argv[2]);
    strcat(binary, argv[3]);

    unsigned int x = strtoul(binary, NULL, 2);
    float *ptr = (float *)&x;
    printf("f - %f\n", *ptr);
}