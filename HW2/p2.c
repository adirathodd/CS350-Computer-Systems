#include <stdio.h>
#include <limits.h>
#include <string.h>

void print_line(int x){
    for (int i = 0; i < x; i++) printf("-");
    printf("\n");
}

int main(){
    // Print header center align
    int width = 100;
    char text[] = "Word size w";
    int padding = (width - strlen(text)) / 2;
    printf("%*s%s%*s\n", padding, "", text, padding, "");
    print_line(80);    

    // Print second row 'Value 8 16 32 64'
    printf("%-10s %-8d %-8d %-20d %-40d\n", "Value", 8, 16, 32, 64);
    print_line(80);

    int w[4] = {8, 16, 32, 64};

    // Print Unsigned max
    unsigned long long max = ULLONG_MAX;

    printf("%-10s", "U Max(w)");

    printf("0x%-8llX", (max >> (64 - 8)));
    printf("0x%-8llX", (max >> (64 - 16)));
    printf("0x%-20llX", (max >> (64 - 32)));
    printf("0x%-40llX\n", (max >> (64 - 64)));

    printf("%-10s", "");

    printf("%-10llu", (max >> (64 - 8)));
    printf("%-10llu", (max >> (64 - 16)));
    printf("%-22llu", (max >> (64 - 32)));
    printf("%-42llu\n\n", (max >> (64 - 64)));

    // Print Signed min
    long long min = LLONG_MIN;

    printf("%-10s", "T Min(w)");

    printf("0x%-8X", (min >> (64 - 8)) & 0xFF);
    printf("0x%-8X", (min >> (64 - 16)) & 0xFFFF);
    printf("0x%-20X", (min >> (64 - 32)) & 0xFFFFFFFF);
    printf("0x%-40llX\n", (min >> (64 - 64)) & 0xFFFFFFFFFFFFFFFF);

    printf("%-10s", "");

    printf("%-10d", (min >> (64 - 8)));
    printf("%-10d", (min >> (64 - 16)));
    printf("%-22lld", (min >> (64 - 32)));
    printf("%-42lld\n\n", (min >> (64 - 64)));

    // Print Signed max
    long long signed_max = LLONG_MAX;

    printf("%-10s", "T Max(w)");

    printf("0x%-8llX", (signed_max >> (64 - 8)));
    printf("0x%-8llX", (signed_max >> (64 - 16)));
    printf("0x%-20llX", (signed_max >> (64 - 32)));
    printf("0x%-40llX\n", (signed_max >> (64 - 64)));

    printf("%-10s", "");

    printf("%-10lld", (signed_max >> (64 - 8)));
    printf("%-10lld", (signed_max >> (64 - 16)));
    printf("%-22lld", (signed_max >> (64 - 32)));
    printf("%-42lld\n\n", (signed_max >> (64 - 64)));

    // Print -1
    long long neg_one = -1;

    printf("%-10s", "-1");

    printf("0x%-8llX", (neg_one >> (64 - 8)) & 0xFF);
    printf("0x%-8llX", (neg_one >> (64 - 16)) & 0xFFFF);
    printf("0x%-20llX", (neg_one >> (64 - 32)) & 0xFFFFFFFF);
    printf("0x%-40llX\n\n", (neg_one >> (64 - 64)) & 0xFFFFFFFFFFFFFFFF );

    // Print 0
    long long zero = 0;

    printf("%-10s", "0");

        char col2[10];
    snprintf(col2, sizeof(col2), "0x%02llX", (zero >> (64 - 8)) & 0xFF);
    
    char col3[12];
    snprintf(col3, sizeof(col3), "0x%04llX", (zero >> (64 - 16)) & 0xFFFF);
    
    char col4[16];
    snprintf(col4, sizeof(col4), "0x%08llX", (zero >> (64 - 32)) & 0xFFFFFFFF);
    
    char col5[22];
    snprintf(col5, sizeof(col5), "0x%016llX", (zero >> (64 - 64)) & 0xFFFFFFFFFFFFFFFF);

    printf("%-10s", col2);
    printf("%-10s", col3);
    printf("%-22s", col4);
    printf("%-42s\n", col5);

    print_line(80);

    return 0;
}