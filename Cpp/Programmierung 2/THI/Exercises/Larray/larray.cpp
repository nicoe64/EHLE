// Demoprogramm zur Speicherfreigabe: [new] und [delete]/[destructor "~"]

#include "larray.h"
#include <iostream>
using namespace std;

Larray::Larray(const int pNumber) {
    number = pNumber;
    ptr = new float[number];
    for (int i = 0; i< number; i++)
        ptr[i] = 0.0;
    cout << "array created\n";
}

// Destruktor
Larray::~Larray() {
    delete[] ptr;
    cout << "array deleted\n";
}

int main() {
    Larray lar(1000);
}