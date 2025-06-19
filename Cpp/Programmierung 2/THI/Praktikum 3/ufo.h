// Nicolas Ehle, Praktikum 2
// Abgabe am 29.04.2024

#include <string>
#include <vector>
#include "ufosim.h"

#ifndef UFO_H
#define UFO_H

using namespace std;

class Ufo {
    protected:
        string id;
        Ufosim* sim;

    public:
        Ufo(const string& pId);
        virtual ~Ufo();
        const string& getId() const;
        vector<float> getPosition() const;
        float getFtime() const;
        virtual void flyToDest(const float x, const float y, const float height, const int speed) const = 0;
        static float angle(const float x1, const float y1, const float x2, const float y2);
        Ufosim* getSim() const {return sim;}

};




#endif // UFO_H