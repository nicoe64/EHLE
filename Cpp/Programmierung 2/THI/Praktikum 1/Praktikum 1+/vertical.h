// Nicolas Ehle, Praktikum 1
// Abgabe am 22.04.2024

#include <string>
#include <vector>
using namespace std;

#ifndef VERTICAL_H
#define VERTICAL_H

#include "ufosim.h"

class Vertical {
    const static string type;
    string id;
    Ufosim* sim;
public:
    Vertical(const string& pId);
    ~Vertical();
    static string getType();
    const string& getId() const;
    vector<float> getPosition() const;
    float getFtime() const;
    void flyToDest(const float x, const float y, const float height, const int speed) const;
    static float angle(const float x1, const float y1, const float x2, const float y2);
};



#endif //VERTICAL_H
