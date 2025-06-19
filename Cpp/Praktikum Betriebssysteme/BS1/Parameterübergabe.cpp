#include <iostream>
#include <thread>
#include <cstring> // Für strlen

#define MAX_NAME_LENGTH 50

// Datenstruktur für den Studenten
struct Student {
    char name[MAX_NAME_LENGTH];
    size_t name_length;
};

// Thread-Funktion
void example_fct(Student *student) {
    // Berechnung der Länge des Namens
    student->name_length = std::strlen(student->name);

}

int main() {
    // Lege einen Übergabeparameter an
    Student student;

    std::cout << "Gib einen Namen ein: ";
    std::cin.ignore(); // Ignores any newline character left in the input buffer
    std::cin.getline(student.name, MAX_NAME_LENGTH);

    // Starte einen Thread mit der auszuführenden Funktion example_fct.
    // Zudem wird ein Parameter übergeben.
    std::thread thread(example_fct, &student);



    // Warte auf Beendigung des Threads
    thread.join();

    // Ausgabe der Inhalte der Datenstruktur
    std::cout << "Name: " << student.name << std::endl;
    std::cout << "Länge des Namens: " << student.name_length << std::endl;

    return 0;
}