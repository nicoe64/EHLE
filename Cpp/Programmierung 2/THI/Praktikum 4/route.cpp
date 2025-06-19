#include <vector>
#include <utility> // Für std::pair

#include "route.h"
#include <cmath>
#include <algorithm>

using namespace std;


// Konstruktor
Route::Route(float pHeight, float (*pDist)(float x1, float y1, float x2, float y2, float h)) {
    height = pHeight;
    dist = pDist;
    destinations = new vector<pair<float, float>>();
}

// Destruktor
Route::~Route() {
    delete destinations;
}

void Route::add(const float destX, const float destY) {
    destinations->emplace_back(destX, destY);
}

const vector<pair<float, float>>& Route::getDestinations()  {
    return *destinations;
}

const float Route::getHeight() {
    return height;
}

const void Route::setHeight(float pHeight) {
    height = pHeight;
}

void Route::setDist(float (*pDist)(float x1, float y1, float x2, float y2, float h)) {
    dist = pDist;
}

float Route::distance() {
    if (destinations->empty()) return 0.0f; // Wenn keine Ziele vorhanden sind, ist die Entfernung 0
    
    float totalDist = 0.0f;
    
    // Entfernung vom Startpunkt zur ersten Zieldestination
    auto distToFirst = dist(0.0f, 0.0f, (*destinations)[0].first, (*destinations)[0].second, height);
    totalDist += distToFirst;
    
    // Gesamtentfernung zwischen den Zielen
    for (size_t i = 0; i < destinations->size() - 1; ++i) {
        auto distBetween = dist((*destinations)[i].first, (*destinations)[i].second,
                                (*destinations)[i + 1].first, (*destinations)[i + 1].second, height);
        totalDist += distBetween;
    }
    
    // Entfernung von der letzten Zieldestination zum Startpunkt
    auto distBackToStart = dist((*destinations).back().first, (*destinations).back().second, 0.0f, 0.0f, height);
    totalDist += distBackToStart;

    return totalDist;
}

void Route::shortestRoute() {
    if (destinations->empty()) return; // Wenn keine Ziele vorhanden sind, gibt es keine Route
    
    vector<pair<float, float>> bestRoute = *destinations;
    
    float minDist = std::numeric_limits<float>::max(); // Die minimale Entfernung wird auf den größtmöglichen Wert initialisiert
    
    std::sort(destinations->begin(), destinations->end()); // Sortiere die Ziele, um alle Permutationen zu erhalten
    
    // Durchlaufe alle Permutationen und aktualisiere die beste Route, falls eine kürzere gefunden wird
    do {
        float currentDist = distance(); // Berechne die Entfernung der aktuellen Route
        if (currentDist < minDist) { // Wenn die aktuelle Entfernung kürzer ist als die bisher kürzeste
            minDist = currentDist; // Aktualisiere die minimale Entfernung
            bestRoute = *destinations; // Aktualisiere die beste Route
        }
    } while (std::next_permutation(destinations->begin(), destinations->end())); // Durchlaufe alle Permutationen
    
    *destinations = bestRoute; // Setze die beste Route als die endgültige Route
}
