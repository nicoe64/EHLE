// Nicolas Ehle, Praktikum 2
// Abgabe am 29.04.2024

#include "ballistic.h"
#include "ufo.h"
#include "vertical.h"
#include <cmath>
#include <utility>

// constructor for Ballistic

Ballistic::Ballistic(const std::string& pId, const float pTakeOffAngle, const float pLandingAngle) : Ufo(pId)
{
    if(pTakeOffAngle > 0.0 && pTakeOffAngle <= 90.0)                    
    {
        takeOffAngle = pTakeOffAngle;
    } else {                                                            
        takeOffAngle = 45.0;
    }
    
    if(pLandingAngle > 0.0 && pLandingAngle <= 90.0)                    
    {
        landingAngle = pLandingAngle;
    } else {                                                            
        landingAngle = 45.0;
    }
}

float Ballistic::getTakeOffAngle() const
{
    return takeOffAngle;
}

float Ballistic::getLandingAngle() const
{
    return landingAngle;
}

std::vector<float> Ballistic::firstWaypoint(const float x, const float y, const float height) const
{
    std::vector<float> startPosition = getPosition();

    // Helper function to normalize a vector
    auto normalizeVector = [](float x, float y) -> std::pair<float, float> {
        float length = std::hypot(x, y);
        return {x / length, y / length};
    };

    // Helper function to calculate the waypoint
    auto calculateWaypoint = [](const std::vector<float>& startPosition, float directionVectorX, float directionVectorY, float distance) -> std::vector<float> {
        float xEnde = startPosition[0] + directionVectorX * distance;
        float yEnde = startPosition[1] + directionVectorY * distance;
        return {xEnde, yEnde};
    };

    float dx = x - startPosition[0];
    float dy = y - startPosition[1];
    auto [normX, normY] = normalizeVector(dx, dy);

    float takeOffAngleRad = getTakeOffAngle() * (M_PI / 180.0);
    float distanceFirstPoint = height / std::tan(takeOffAngleRad);

    return calculateWaypoint(startPosition, normX, normY, distanceFirstPoint);
}

std::vector<float> Ballistic::secondWaypoint(const float x, const float y, const float height) const
{
    std::vector<float> initialPosition = getPosition();

    // Helper function to normalize a vector
    auto normalizeVector = [](float x, float y) -> std::pair<float, float> {
        float length = std::hypot(x, y);
        return {x / length, y / length};
    };

    // Helper function to calculate the waypoint
    auto calculateWaypoint = [](const std::vector<float>& initialPosition, float directionVectorX, float directionVectorY, float distance) -> std::vector<float> {
        float xFinal = initialPosition[0] + directionVectorX * distance;
        float yFinal = initialPosition[1] + directionVectorY * distance;
        return {xFinal, yFinal};
    };

    float directionVectorX = x - initialPosition[0];
    float directionVectorY = y - initialPosition[1];
    auto [normX, normY] = normalizeVector(directionVectorX, directionVectorY);

    float landingAngleRad = getLandingAngle() * (M_PI / 180.0);
    float lengthDirectionVector = std::hypot(x - initialPosition[0], y - initialPosition[1]);
    float distanceSecondPoint = lengthDirectionVector - (height / std::tan(landingAngleRad));

    return calculateWaypoint(initialPosition, normX, normY, distanceSecondPoint);
}

void Ballistic::flyToDest(const float x, const float y, const float height, const int speed) const
{
    std::vector<float> Dest1 = firstWaypoint(x, y, height);
    std::vector<float> Dest2 = secondWaypoint(x, y, height);

    sim->flyTo(Dest1[0], Dest1[1], height, speed, speed);
    sim->flyTo(Dest2[0], Dest2[1], height, speed, speed);
    sim->flyTo(x, y, 0, speed, 0);
}
