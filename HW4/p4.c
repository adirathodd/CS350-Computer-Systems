#include <stdio.h>
#include <stdlib.h>

//            %rdx,   %rsi,   %rdi
long decode2(long x, long y, long z){
    y -= z;
    x *= y;

    return x ^ ((y << 63) >> 63);
}

int main(){
    long x = 1, y = 2, z = 2;
    decode(x, y , z);
}