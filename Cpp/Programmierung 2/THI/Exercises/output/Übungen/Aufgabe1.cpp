/*
  Tutorium Grundlagen der Programmierung 2 - Tutorium
  Aufgabe 1: Einlesen und Ausgabe von Daten
*/
#include <iostream>
using namespace std;

int main() {
  string Name;
  int Alter;
  string Volljährigkeit;
  int Postleitzahl;
  string Z;

  cout << "Geben Sie Ihren Namen ein:\n";
  cin >> Name;

  cout << "Geben Sie Ihr Alter in Jahren ein:\n";
  cin >> Alter;

  cout << "Geben Sie Ihre Postleitzahl ein:\n";
  cin >> Postleitzahl;

  if (Alter < 18) {
    Volljährigkeit = "minderjaehrig";
  } else if (Alter >= 18) {
    Volljährigkeit = "volljaehrig";
  }
  
  if (Postleitzahl % 2 == 0) {
    Z = "gerade";
  } else if (Postleitzahl % 2 == 1) {
    Z = "ungerade";
  }

  cout << "Sie heissen " << Name << " und sind " << Volljährigkeit << endl;
  cout << "Ihre Postleitzahl ist " << Z;

  return 0;
}
