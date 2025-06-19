/*
  Tutorium Grundlagen der Programmierung 2 - Tutorium
  Aufgabe 6
*/

#include "bauwerk.h"
#include <iostream>
#include <cmath>

/* Ihre Implementationen hier. */

Bauwerk::Bauwerk(float hoehe, float grundflaeche, unsigned int stockwerke) {
  this->hoehe;
  this->grundflaeche = grundflaeche;
  this->stockwerke = stockwerke;
}

float Bauwerk::getHoeheProStockwerk() {
  return hoehe / stockwerke;
}

float Bauwerk::getGesamtFlaeche(){
  return grundflaeche * grundflaeche;
}

bool Bauwerk::isHochhaus() {
  return (stockwerke >= 4);
}

bool Bauwerk::isWolkenkratzer() {
  return isHochhaus() && (hoehe >= 150);
}

void Bauwerk::erweitereUmStockwerk() {
  hoehe += getHoeheProStockwerk();
  ++stockwerke;
}

float Bauwerk::flaecheProPerson(unsigned int personen) {
  return getGesamtFlaeche() / personen;
}


int main() {
  Bauwerk a = Bauwerk(160, 200, 2);
  Bauwerk b = Bauwerk(141, 150, 3);
  Bauwerk c = Bauwerk(80, 220, 5);

  if (a.isHochhaus()) {
    std::cout << "[01] Fehler in isHochhaus()." << std::endl;
  }

  if (b.isHochhaus()) {
    std::cout << "[02] Fehler in isHochhaus()." << std::endl;
  }

  b.erweitereUmStockwerk();

  if (std::abs(b.hoehe - 188) > 0.1) {
    std::cout << "[03] Fehler in erweitereUmStockwerk()." << std::endl;
  }

  if (b.stockwerke != 4) {
    std::cout << "[04] Fehler in erweitereUmStockwerk()." << std::endl;
  }

  if (!b.isHochhaus()) {
    std::cout << "[05] Fehler in isHochhaus() oder erweitereUmStockwerk()." << std::endl;
  }

  if (!c.isHochhaus()) {
    std::cout << "[06] Fehler in isHochhaus()." << std::endl;
  }

  if (a.isWolkenkratzer()) {
    std::cout << "[07] Fehler in isWolkenkratzer()." << std::endl;
  }

  if (!b.isWolkenkratzer()) {
    std::cout << "[08] Fehler in isWolkenkratzer()." << std::endl;
  }

  if (c.isWolkenkratzer()) {
    std::cout << "[09] Fehler in isWolkenkratzer()." << std::endl;
  }

  if (std::abs(a.flaecheProPerson(4) - 100) > 0.1) {
    std::cout << "[10] Fehler in flaecheProPerson()." << std::endl;
  }

  if (std::abs(b.flaecheProPerson(24) - 25) > 0.1) {
    std::cout << "[11] Fehler in flaecheProPerson()." << std::endl;
  }

  if (std::abs(c.flaecheProPerson(10) - 110) > 0.1) {
    std::cout << "[12] Fehler in flaecheProPerson()." << std::endl;
  }

  return 0;
}
