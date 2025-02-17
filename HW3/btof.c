#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
    // V = (-1)^2 * (2^E) * M

    int sign = strtol(argv[1], NULL, 2);
    int stored_e = strtol(argv[2], NULL, 2), exponent;

    float val = powf(2, -1), mantissa;

    if(stored_e > 0) {
        mantissa = 1.0;
        exponent = stored_e - 127;
    } else {
        mantissa = 0.0;
        exponent = -126;
    }

    for(int i = 0; i < 23; i++){
        if(argv[3][i] == '1'){
            mantissa += val;
        }
        val /= 2;
    }

    printf("sign = %d, exponent =  %d, mantissa = %0.26f\n", sign, exponent, mantissa);

    float result = powf(1, sign) * powf(2, exponent) * mantissa;

    printf("result = %0.26f\n", result);
}