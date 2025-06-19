
#include <stdio.h>

#define ROWS 99
#define COLS 99

char Spielfeld[ROWS][COLS];

void initSpielfeld() {
    // Spielfeld initialisieren
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == ROWS / 2 || j == COLS / 2) {
                Spielfeld[i][j] = '*';
            } else {
                Spielfeld[i][j] = '_';
            }
        }
    }
}

void printSpielfeld() {
    // Spielfeld anzeigen
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", Spielfeld[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initSpielfeld();
    
    // Muster einfügen (z.B. Kreuz)
    Spielfeld[ROWS / 2][COLS / 2] = '*';

    printSpielfeld();

    return 0;
}