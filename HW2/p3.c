#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(){

    printf("%10s %10s %10s\n", "Binary", "Unsigned", "Signed");

    for(unsigned short int i = 0; i < 32; i++){
        printf("     ");

        for(int j = 4; j >= 0; j--){
            printf("%d", (i >> j) & 1);
        }

        printf("%10d", i);
        
        int sign = ((i & 0x1F) << 27) >> 27;
        printf("%10d\n", sign);
    }
}