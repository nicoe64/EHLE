// Nicolas Ehle, Praktikumsaufgabe 3
// Abgabe am 20.03.24

#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include <algorithm>

using namespace std;

class Route {
    private:
        vector<std::pair<float,float>>* destinations;
        float height;
        float (*dist) ( float x1, float y1, float x2, float y2, float h);
    
    public:
        Route(float pHeight, float (*pDist)(float x1, float y1, float x2, float y2, float h));
        ~Route();
        void add(const float destX, const float destY);
        const vector<pair<float,float>> &getDestinations();
        const float getHeight();
        const void setHeight(float pHeight);
        void setDist(float (*pDist)(float x1, float y1, float x2, float y2, float h));
        float distance();
        void shortestRoute();

};

#endif // ROUTE_H

