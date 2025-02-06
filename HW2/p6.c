#include <stdio.h>
#include <limits.h>
#include <math.h>

void print_bits(int x){
    for(int i = (sizeof(int) * 8 - 1); i >= 0; i--) printf("%d", (x >> i) & 1);
    printf("\n");
}

int saturating_add(int x, int y){
    unsigned int sum = x + y, w = sizeof(int) * 8;
    
    unsigned int msb_x = (x >> (w - 1)) & 1, msb_y = (y >> (w - 1)) & 1, msb_sum = (sum >> (w - 1)) & 1;

    int positive_overflow = ~msb_x & ~msb_y & msb_sum;
    int negative_overflow = msb_x & msb_y & ~msb_sum;

    int result = (sum & ~(-positive_overflow | -negative_overflow)) | (-positive_overflow & INT_MAX) | (-negative_overflow & INT_MIN);

    return result;
}

int main(){
    // Positive overflow
    printf("INT_MAX + 5 = %d\n", saturating_add(INT_MAX, 5));

    // Negative overflow
    printf("INT_MIN + -5 = %d\n", saturating_add(INT_MIN, -5));

    // Normal
    printf("5 + 5 = %d\n", saturating_add(5, 5));
    
}