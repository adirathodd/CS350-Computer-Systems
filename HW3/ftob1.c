#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BIAS 127
#define LEN 32
#define EXP_32 8
#define MAN_32 9

int main(int argc, char *argv[]){
    // seperate the whole number and decimal
    int x = strtol(argv[1], NULL, 10);
    float y = strtof(argv[1], NULL) - (float) x;

    printf("%d + %f\n", x, y);

    char binary[32] = " ";

    // sign bit
    binary[0] = (x < 0) ? '1' : '0';    
    int i, bit, char_index = 0;
    int first_one = 0;

    // calculate actual exponent
    char expon[8] = " ";

    for(i = 7; i >= 0; i--){
        bit = (x >> i) & 0x1;
        if(bit == 1){
            if(!first_one){
                first_one = char_index;
            }
            expon[char_index++] = '1';
        } else {
            expon[char_index++] = '0';
        }
    }

    printf("binary exponent - %s\n", expon);
    
    // calculate mantissa
    char mantis[23] = "";
    
    for(i = 0; i < 23; i++){
        y *= 2;

        if (y >= 1){
            mantis[i] = '1';
            y -= 1;
        } else {
            mantis[i] = '0';
        }
    }

    printf("binary mantissa - %s\n", mantis);
    unsigned int stored_e = (8 - first_one - 1) + BIAS;
    printf("stored exp - %d\n\n", stored_e);

    // write exponent and fraction section to result
    char_index = 1;
    for(i = 7; i >= 0; i--){
        bit = ((stored_e >> i) & 1);
        
        if(bit == 1){
            binary[char_index++] = '1';
        } else {
            binary[char_index++] = '0';
        }
    }

    for(i = first_one + 1; i < 8; i++){
        binary[char_index++] = expon[i];
    }

    int j = 0;

    for(i = char_index; i < 32; i++){
        binary[i] = mantis[j++];
    }

    printf("result - %s\n", binary);
}