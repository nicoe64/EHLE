// Nicolas Ehle, Praktikum 2
// Abgabe am 29.04.2024

#include "vertical.h"
#include "ufo.h"
#include "ufosim.h"
#include <cmath>


// Konstruktor                                                     
Vertical::Vertical(const string& pId) : Ufo(pId){

}

// Dekonstruktor
Vertical::~Vertical() {

}
void Vertical::flyToDest(const float x, const float y, const float height, const int speed) const {
    Ufosim* sim = getSim();

    sim->flyTo(sim->getX(), sim->getY(), height, speed, 0);
    sim->flyTo(x, y, height, speed, 0);
    sim->flyTo(x, y, 0, speed, 0);
}