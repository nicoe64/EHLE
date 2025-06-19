// Nicolas Ehle, Praktikum 2
// Abgabe am 29.04.2024

#include <string>
#include <vector>
using namespace std;

#ifndef VERTICAL_H
#define VERTICAL_H

#include "ufo.h"
#include "ufosim.h"

class Vertical: public Ufo {
public:
    Vertical(const string& pId); // Konstruktor
    ~Vertical(); // Dekonstruktor


    void flyToDest(const float x, const float y, const float height, const int speed) const override;
    
};



#endif //VERTICAL_H
