#include <stdio.h>

int multitable[10][10];

void mtable(int a) {
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            multitable[i][j] = a * (i + 1) * (j + 1);
            printf("%d ", multitable[i][j]);
        }
        printf("\n"); // Neue Zeile nach jeder Zeile der Multiplikationstabelle
    }
}

int main() {
    int a;
    printf("Bitte gib eine positive Zahl ein:\n");
    if (scanf("%d", &a) != 1 || a <= 0) { // Überprüfung der Eingabe
        printf("Bitte gib eine positive Zahl ein!\n");
        return 0;
    }

    mtable(a);
    return 0;
}
