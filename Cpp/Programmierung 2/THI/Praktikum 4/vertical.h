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

    static float distance(const float x1, const float y1, const float x2, const float y2, const float h);
    static float calculateVerticalDistance(const float x_start, const float y_start, const float x_end, const float y_end, const float height);
};



#endif //VERTICAL_H
