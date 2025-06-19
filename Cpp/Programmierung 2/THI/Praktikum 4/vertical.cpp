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

float Vertical::distance(const float x1, const float y1, const float x2, const float y2, const float h) {
    float totalVerticalDist = 0.0f;

    if (h < 0) {
        return totalVerticalDist;
    } else {
        // Innere Funktion zur Berechnung der vertikalen Strecke zwischen zwei Punkten
        auto computeVerticalDistance = [](float x1, float y1, float x2, float y2, float h) {
            // Berechnung der horizontalen Distanz zwischen (x1, y1) und (x2, y2)
            float horizontalDistance = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));

            // Berechnung der Gesamtdistanz (Aufstieg + Abstieg)
            float totalDistance = 2 * std::abs(h) + horizontalDistance;

            return totalDistance;
        };

        totalVerticalDist += computeVerticalDistance(x1, y1, x2, y2, h);
    }

    return totalVerticalDist;
}