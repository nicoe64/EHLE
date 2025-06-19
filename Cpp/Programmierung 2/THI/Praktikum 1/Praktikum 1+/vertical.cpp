// Nicolas Ehle, Praktikum 1
// Abgabe am 22.04.2024

#include "vertical.h"
#include "ufosim.h"
#include <cmath>


const string Vertical::type = "vertical";

// Konstruktor
Vertical::Vertical(const string &pId) {
    Ufosim::setSpeedup(4);
    sim = new Ufosim();
    id = pId;
}

// Dekonstruktor
Vertical::~Vertical() {
    delete sim;
}

string Vertical::getType() {
    return type;
}

const string & Vertical::getId() const {
    return id;
}

vector<float> Vertical::getPosition() const {
    vector<float>position;
    position.push_back(sim->getX());
    position.push_back(sim->getY());
    position.push_back(sim->getZ());
    return position;
}

float Vertical::getFtime() const {
    return sim->getFtime();
}

void Vertical::flyToDest(const float x, const float y, const float height, const int speed) const {
    sim->flyTo(sim->getX(), sim->getY(), height, speed, 0);
    sim->flyTo(x, y, height, speed, 0);
    sim->flyTo(x, y, 0, speed, 0);
}

// Winkelberechnung
float Vertical::angle(const float x1, const float y1, const float x2, const float y2) {
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
    float winkelInDeg = winkelInRad * (180.0 / M_PI);

    // Winkelberechnugn zwischen y-Achse und Linie
    winkelInDeg = 90 - winkelInDeg;

    // Addition von 360, wenn der Winkel negativ ist
    if (winkelInDeg < 0) {
        winkelInDeg += 360;
    }
                                                                                      
    return winkelInDeg;
}