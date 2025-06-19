#include <stdio.h>

// Funktionsprototypen
void notenEingabe(int noten[], int anzahl);
void notenAusgabe(int noten[], int anzahl);
void durchschnittsnote(int noten[], int anzahl);
void hochundtief(int noten[], int anzahl);
void showmenu(int *option);

int main() {
    int anzahl = 6;
    int noten[anzahl];
    int option;

    printf("Willkommen zur Studentennotenverwaltung!\n\n");
    printf("Bitte geben Sie die Anzahl der Studenten ein: ");
    scanf("%d", &anzahl);

    printf("Anzahl der Studenten: %d\n\n", anzahl);
    
    notenEingabe(noten, anzahl);

    do {
        showmenu(&option);

        switch(option) {
            case 1:
                notenAusgabe(noten, anzahl);
                break;
            case 2:
                durchschnittsnote(noten, anzahl);
                break;
            case 3:
                hochundtief(noten, anzahl);
                break;
            case 4:
                printf("Programm beendet.\n");
                break;
            default:
                printf("Ungültige Option. Bitte wählen Sie erneut.\n");
        }
    } while(option != 4);

    return 0;
}

void notenEingabe(int noten[], int anzahl) {
    for (int i = 0; i < anzahl; i++) {
        printf("Note für Student %d: ", i + 1);
        scanf("%d", &noten[i]);
    }
}

void notenAusgabe(int noten[], int anzahl) {
    printf("\nNoten der Studenten:\n");
    for (int i = 0; i < anzahl; i++) {
        printf("Student %d: %d\n", i + 1, noten[i]);
    }
}

void durchschnittsnote(int noten[], int anzahl) {
    // Implementierung der Durchschnittsnote hier
    // Zum Beispiel:
    float summe = 0.0;
    for (int i = 0; i < anzahl; i++) {
        summe += noten[i];
    }
    float durchschnitt = summe / anzahl;
    printf("\nDurchschnittsnote: %.2f\n", durchschnitt);
}

void hochundtief(int noten[], int anzahl) {
    // Implementierung für höchste und niedrigste Note hier
    // Zum Beispiel:
    int max = noten[0];
    int min = noten[0];
    
    for (int i = 1; i < anzahl; i++) {
        if (noten[i] > max) {
            max = noten[i];
        }
        if (noten[i] < min) {
            min = noten[i];
        }
    }
    
    printf("\nHöchste Note: %d\n", max);
    printf("Niedrigste Note: %d\n", min);
}

void showmenu(int *option) {
    printf("\nMenü:\n");
    printf("1. Noten anzeigen\n");
    printf("2. Durchschnittsnote berechnen\n");
    printf("3. Höchste und niedrigste Note anzeigen\n");
    printf("4. Beenden\n");
    printf("\nBitte wählen Sie eine Option: ");
    scanf("%d", option);
}
