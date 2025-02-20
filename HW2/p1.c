#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>   // For int8_t

int main(){
    unsigned short int hex[8];
    hex[0] = 0x0A;
    hex[1] = 0x06;
    hex[2] = 0x14;
    hex[3] = 0x6B;
    hex[4] = 0x8A;
    hex[5] = 0x86;
    hex[6] = 0x94;
    hex[7] = 0xEB;
    
    printf("%10s %10s %10s %10s\n", "Hex", "Binary", "Unsigned", "Signed");
    for(int i = 0; i < 8; i++){
        printf("%10.2X ", hex[i]);

        printf("  ");
        for(int j = 7; j >= 0; j--){
            printf("%d", (hex[i] >> j) & 1);
        }

        printf("%10d ", hex[i]);

        int sign = (int)((int8_t)(hex[i] & 0xFF));
        printf("%10d\n", sign);
    }
}