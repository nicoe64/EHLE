/*
  Tutorium Grundlagen der Programmierung 2 - Tutorium
  Aufgabe 6
*/

#pragma once

class Bauwerk {
public:
  // Konstruktor.
  Bauwerk(float hoehe, float grundflaeche, unsigned int stockwerke);

  // Höhe in [m].
  float hoehe;

  // Grundfläche in [m²].
  float grundflaeche;
  
  // Anzahl der Stockwerke.
  unsigned int stockwerke;

  // Bebäudehöhe pro Stockwerk in [m].

  float getHoeheProStockwerk();

  // Bodenfläche mal Stockwerke in [m²].

  float getGesamtFlaeche();

  // Ein Gebäude gilt ab 4 Stockwerken als Hochhaus.

  bool isHochhaus();

  // Ein Hochhaus gilt ab einer Höhe von 150m als Wolkenkratzer.
  
  bool isWolkenkratzer();

  // Baue ein Stockwerk mit der durschnittlichen Stockwerkhöhe hinzu.

  void erweitereUmStockwerk();

  // Anzahl an Fläche in dem Gebäude pro Person in [m²].

  float flaecheProPerson(unsigned int personen);
};
