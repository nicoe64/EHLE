#include <stdio.h>

void drucke(int n) {
    int a, e, i, o, u, x;
    
    // Drucke die Ziffer 5
    for (a = 0; a < n + 4; a++) {
        printf("*");
    }
    printf("\n");

    for (e = 0; e < n; e++) {
        printf("*\n");
    }
    printf("\n");

    for (i = 0; i < n + 3; i++) {
        printf("*");
    }
    printf("");
    printf("\n");

    for (o =0; o<n; o++) {
    for (u=0; u == n+4; u++) {
        printf("*\n");
    }
    }
    printf("\n");

    for (x = 0; x < n + 3; x++) {
        printf("*");
    }
}

int main() {
    drucke(1);
    return 0;
}