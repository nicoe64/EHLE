#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Erstellen eines Vektors vec1 von Pointer auf int.
    // Der Vektor soll zwei Pointer enthalten.
    // Die beiden Pointer sollen auf zwei beliebige int-Werte
    // auf dem Heap zeigen.
    int* a = new int (5);
    int* b = new int (10);
    vector<int*> vec1{a, b};

    // Konsolausgabe von vec1. Die beiden int-Werte sollen ausgegeben werden.
    cout << *vec1[0] << ' ' << *vec1[1] << ' ' << "\n";

    // Erstellen eines Vektors vec2.
    // Der Vektor vec2 soll mit dem Copy-Konstruktor kopiert werden.
    vector<int*> vec2(vec1);

    // Konsolausgabe von vec2. Die beiden int-Werte sollen ausgegeben werden.
    cout << *vec2[0] << ' ' <<  *vec2[1] << ' ' << "\n";

    // Der int-Wert auf den vec1[0] zeigt, soll geaendert werden.
    *vec1[0] = *vec1[0] * 3;

    // Konsolausgabe von vec1. Die beiden int-Werte sollen ausgegeben werden.
    cout << *vec1[0] << ' ' << *vec1[1] << ' ' << "\n";

    // Konsolausgabe von vec2. Die beiden int-Werte sollen ausgegeben werden.
    cout << *vec2[0] << ' ' <<  *vec2[1] << ' ' << "\n";

    // Auch der int-Wert, auf den vec2[0] zeigt, hat sich geaendert.
    // vec2 ist eine flache Kopie (shallow copy) von vec1.
    return 0;
}