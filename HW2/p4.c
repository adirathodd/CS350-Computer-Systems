#include <limits.h>
#include <stdio.h>

int main(){
    int signed_1 = 0, signed_2;
    unsigned int unsigned_1 = 0, unsigned_2;

    printf("%15s%20s%10s%15s\n", "Constant 1", "Constant 2", "Relation", "True or False");

    // 0 == 0U
    if(signed_1 == unsigned_1){
        printf("%15d%19uU%10s%15s\n", signed_1, unsigned_1, "==", "True");
    } else {
        printf("%15d%19uU%10s%15s\n", signed_1, unsigned_1, "==", "False");
    }

    signed_2 = -1;

    // -1 < 0
    if(signed_2 < signed_1){
        printf("%15d%20d%10s%15s\n", signed_2, signed_1, "<", "True");
    } else {
        printf("%15d%20d%10s%15s\n", signed_2, signed_1, "<", "False");
    }

    // -1 > 0U
    if(signed_2 > unsigned_1){
        printf("%15d%19dU%10s%15s\n", signed_2, unsigned_1, ">", "True");
    } else {
        printf("%15d%19dU%10s%15s\n", signed_2, unsigned_1, ">", "False");
    }

    signed_1 = INT_MAX;
    signed_2 = INT_MIN;

    // Tmax > TMin
    if(signed_1 > signed_2){
        printf("%15d%20d%10s%15s\n", signed_1, signed_2, ">", "True");
    } else {
        printf("%15d%20d%10s%15s\n", signed_1, signed_2, ">", "False");
    }

    unsigned_1 = (unsigned int) INT_MAX;

    // TMaxU > TMin
    if(unsigned_1 < signed_2){
        printf("%14uU%20d%10s%15s\n", unsigned_1, signed_2, "<", "True");
    } else {
        printf("%14uU%20d%10s%15s\n", unsigned_1, signed_2, "<", "False");
    }
    signed_1 = -1, signed_2 = -2;

    // -1 > -2
    if(signed_1 > signed_2){
        printf("%15d%20d%10s%15s\n", signed_1, signed_2, ">", "True");
    } else {
        printf("%15d%20d%10s%15s\n", signed_1, signed_2, ">", "False");
    }

    // (unsigned)-1 > -2
    if((unsigned int)signed_1 > signed_2){
        printf("   (unsigned)%-7d%15d%10s%15s\n", (unsigned int)signed_1, signed_2, ">", "True");
    } else {
        printf("   (unsigned)%-7d%15d%10s%15s\n", (unsigned int)signed_1, signed_2, ">", "False");
    }

    signed_1 = INT_MAX;
    unsigned_1 = (unsigned int)INT_MAX + 1;

    // TMax > TMax+1(unsigned int)
    if (signed_1 < unsigned_1) {
        printf("%15d%19uU%10s%15s\n", signed_1, unsigned_1, "<", "True");
    } else {
        printf("%15d%19uU%10s%15s\n", signed_1, unsigned_1, "<", "False");
    }

    // TMax > (int) TMax(unsigned int)
    if (signed_1 > (int)unsigned_1) {
        printf("%15d   (int)%-10dU%10s%15s\n", signed_1, (int)unsigned_1, ">", "True");
    } else {
        printf("%15d   (int)%15dU%10s%15s\n", signed_1, (int)unsigned_1, ">", "False");
    }
}