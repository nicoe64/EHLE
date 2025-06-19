// Nicolas Ehle, Praktikum 2
// Abgabe am 29.04.2024

#include <string>
#include <vector>

#ifndef BALLISTIC_H
#define BALLISTIC_H

using namespace std;

#include "ufo.h"
#include "ufosim.h"

class Ballistic: public Ufo {
    private:
        string id;
        float takeOffAngle;
        float landingAngle;

    public:
        Ballistic(const string& pid, const float pTakeOffAngle, const float pLandingAngle);

        ~Ballistic(){};

        float getTakeOffAngle() const;
        float getLandingAngle() const;
        virtual void flyToDest(const float x, const float y, const float height, const int speed) const override;
        vector<float> firstWaypoint(const float x, const float y, const float height) const; 
        vector<float> secondWaypoint(const float x, const float y, const float height) const;

};

#endif // BALLISTIC_H