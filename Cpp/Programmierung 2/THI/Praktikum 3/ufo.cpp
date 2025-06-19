// Nicolas Ehle, Praktikum 2
// Abgabe am 29.04.2024

#include "ufo.h"
#include "ufosim.h"
#include <cmath>


// Konstruktor
Ufo::Ufo(const string& pId) {
    id= pId;
    sim = new Ufosim();
}

// Dekonstruktor
Ufo::~Ufo() {
    delete sim;
    // sim = nullptr;
}

const string & Ufo::getId() const {
    return id;
}

vector<float> Ufo::getPosition() const {
    vector<float>position;
    position.push_back(sim->getX());
    position.push_back(sim->getY());
    position.push_back(sim->getZ());
    return position;
}

float Ufo::getFtime() const {
    return sim->getFtime();
}

void Ufo::flyToDest(const float x, const float y, const float height, const int speed) const {
    sim->flyTo(sim->getX(), sim->getY(), height, speed, 0);
    sim->flyTo(x, y, height, speed, 0);
    sim->flyTo(x, y, 0, speed, 0);
}

// Winkelberechnung
float Ufo::angle(const float x1, const float y1, const float x2, const float y2) {
    // Punktgleichheit?
    if (x1 == x2 && y1 == y2) {
        return 0.0;
    }
    // Entfernungsbestimmung
    float diffX = x2 - x1;
    float diffY = y2 - y1;

    // Winkelbestimmung in Rad
    float winkelInRad = atan2(diffY, diffX);

    // Winkelbestimmung in Grad
    float winkelInDeg = winkelInRad * (180.0f / static_cast<float>(M_PI));

    // Winkelberechnugn zwischen y-Achse und Linie
    winkelInDeg = 90 - winkelInDeg; 

    // Addition von 360, wenn der Winkel negativ ist
    if (winkelInDeg < 0) {
        winkelInDeg += 360;
    }
                                                                                      
    return winkelInDeg;
}