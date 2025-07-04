#define BOOST_TEST_MAIN
#include <cmath>
#include <type_traits>
#include <vector>
#include <boost/test/included/unit_test.hpp>
#include "ufo.h"
#include "ballistic.h"
#include "vertical.h"

BOOST_AUTO_TEST_SUITE(pa_utest)

std::vector<float> dest1 = { 10.0, 10.0, 8.0 };
std::vector<float> dest2 = { 10.0, 0.0, 10.0 };
std::vector<float> dest3 = { 30.0, 30.0, 8.0 };
std::vector<float> dest4 = { -10.0, 0.0, 4.0 };
std::vector<float> dest5 = { 10.0, 20.0, 8.0 };
std::vector<float> dest6 = { -20.0, -15.0, 3.0 };

BOOST_AUTO_TEST_CASE(vertical_initially)
{
    std::cout << "Started SomeTest\n";

    Vertical vert("r2d2");
    BOOST_CHECK(vert.getId() == "r2d2");

    BOOST_CHECK(size(vert.getPosition()) == 3);

    if (size(vert.getPosition()) == 3)
    {
        BOOST_CHECK(vert.getPosition()[0] == 0.0);
        BOOST_CHECK(vert.getPosition()[1] == 0.0);
        BOOST_CHECK(vert.getPosition()[2] == 0.0);
    }

    BOOST_CHECK(vert.getFtime() == 0.0);

    std::cout << "Finished SomeTest\n";
}

BOOST_AUTO_TEST_CASE(vertical_after_one_flight)
{
    std::cout << "Started SomeTest\n";

    Vertical vert("r2d2");
    vert.flyToDest(dest1[0], dest1[1], dest1[2], 10);
    BOOST_CHECK(vert.getId() == "r2d2");

    BOOST_CHECK(size(vert.getPosition()) == 3);

    if (size(vert.getPosition()) == 3)
    {
        BOOST_CHECK(fabs(vert.getPosition()[0] - dest1[0]) < 0.1);
        BOOST_CHECK(fabs(vert.getPosition()[1] - dest1[1]) < 0.1);
        BOOST_CHECK(vert.getPosition()[2] == 0.0);
    }

    BOOST_CHECK(fabs(vert.getFtime() - 38.0) < 3);

    std::cout << "Finished SomeTest\n";
}

BOOST_AUTO_TEST_CASE(vertical_after_two_flights)
{
    std::cout << "Started SomeTest\n";

    Vertical vert("r2d2");
    vert.flyToDest(dest1[0], dest1[1], dest1[2], 10);
    vert.flyToDest(dest2[0], dest2[1], dest2[2], 15);
    BOOST_CHECK(vert.getId() == "r2d2");

    BOOST_CHECK(size(vert.getPosition()) == 3);

    if (size(vert.getPosition()) == 3)
    {
        BOOST_CHECK(fabs(vert.getPosition()[0] - dest2[0]) < 0.1);
        BOOST_CHECK(fabs(vert.getPosition()[1] - dest2[1]) < 0.1);
        BOOST_CHECK(vert.getPosition()[2] == 0.0);
    }
    std::cout << "Finished SomeTest\n";
}

BOOST_AUTO_TEST_CASE(ufo_angle)
{
    std::cout << "Started SomeTest\n";

    BOOST_CHECK(fabs(Ufo::angle(1.0, 1.0, 1.0, 1.0) - 0.0) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(0.0, 0.0, 0.0, 1.0) - 0.0) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(0.0, 0.0, 1.0, 2.0) - 26.5651) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(1.0, 1.0, 2.0, 2.0) - 45.0) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(0.0, 0.0, 2.0, 1.0) - 63.4349) < 0.001);

    BOOST_CHECK(fabs(Ufo::angle(1.0, 1.0, 2.0, 1.0) - 90.0) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(0.0, 0.0, 2.0, -1.0) - 116.565) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(-1.0, 1.0, 0.0, 0.0) - 135.0) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(0.0, 0.0, 1.0, -2.0) - 153.435) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(55.0, 20.0, 95.0, -115.0) - 163.496) < 0.001);

    BOOST_CHECK(fabs(Ufo::angle(0.0, 0.0, 0.0, -1.0) - 180.0) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(9.99996185, 9.99996185, 10.0, 0.0) - 180.0) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(0.0, 1.0, -1.0, -3.0) - 194.036) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(0.0, 0.0, -1.0, -2.0) - 206.565) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(0.0, 0.0, -1.0, -1.0) - 225.0) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(0.0, 0.0, -2.0, -1.0) - 243.435) < 0.001);

    BOOST_CHECK(fabs(Ufo::angle(0.0, 0.0, -1.0, 0.0) - 270.0) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(0.0, 0.0, -2.0, 1.0) - 296.565) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(1.0, 1.0, 0.0, 2.0) - 315.0) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(0.0, 0.0, -1.0, 2.0) - 333.435) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(0.0, 0.0, -10.0, 30.0) - 341.565) < 0.001);
    BOOST_CHECK(fabs(Ufo::angle(-1.0, -1.0, -1.9, 30.0) - 358.337) < 0.001);

    std::cout << "Finished SomeTest\n";
}

BOOST_AUTO_TEST_CASE(ballistic_angles)
{
    std::cout << "Started SomeTest\n";

    Ballistic ball("ball", 45.0, 70.0);
    BOOST_CHECK(ball.getTakeOffAngle() == 45.0);
    BOOST_CHECK(ball.getLandingAngle() == 70.0);

    Ballistic ball2("ball2", -10.0, 0.0);
    BOOST_CHECK(ball2.getTakeOffAngle() == 45.0);
    BOOST_CHECK(ball2.getLandingAngle() == 45.0);

    Ballistic ball3("ball3", 275.0, 90.0001);
    BOOST_CHECK(ball3.getTakeOffAngle() == 45.0);
    BOOST_CHECK(ball3.getLandingAngle() == 45.0);

    std::cout << "Finished SomeTest\n";
}

BOOST_AUTO_TEST_CASE(ballistic_polymorphism)
{
    std::cout << "Started SomeTest\n";

    Vertical vert("r2d2");
    Ballistic ball("ball", 45.0, 70.0);
    std::vector<Ufo*> ufos = { &vert, &ball };

    for (Ufo* ufo: ufos)
    {
        ufo->flyToDest(dest3[0], dest3[1], dest3[2], 10);
        BOOST_CHECK(size(ufo->getPosition()) == 3);

        if (size(ufo->getPosition()) == 3)
        {
            BOOST_CHECK(fabs(ufo->getPosition()[0] - dest3[0]) < 0.3);
            BOOST_CHECK(fabs(ufo->getPosition()[1] - dest3[1]) < 0.3);
            BOOST_CHECK(ufo->getPosition()[2] == 0.0);
        }
    }
        std::cout << "Finished SomeTest\n";
}

BOOST_AUTO_TEST_CASE(ballistic_waypoints1)
{
    std::cout << "Started SomeTest\n";

    Ballistic ball("ball", 45.0, 70.0);
    std::vector<float> first = ball.firstWaypoint(dest3[0], dest3[1], dest3[2]);
    std::vector<float> second = ball.secondWaypoint(dest3[0], dest3[1], dest3[2]);

    BOOST_CHECK(size(first) == 2);

    if (size(first) == 2)
    {
        BOOST_CHECK(fabs(first[0] - 5.65685) < 0.1);
        BOOST_CHECK(fabs(first[1] - 5.65685) < 0.1);
    }

    BOOST_CHECK(size(second) == 2);

    if (size(second) == 2)
    {
        BOOST_CHECK(fabs(second[0] - 27.9411) < 0.1);
        BOOST_CHECK(fabs(second[1] - 27.9411) < 0.1);
    }

    std::cout << "Finished SomeTest\n";
}

BOOST_AUTO_TEST_CASE(ballistic_waypoints2)
{
    std::cout << "Started SomeTest\n";

    Ballistic ball("ball", 45.0, 70.0);
    std::vector<float> first = ball.firstWaypoint(dest5[0], dest5[1], dest5[2]);
    std::vector<float> second = ball.secondWaypoint(dest5[0], dest5[1], dest5[2]);

    BOOST_CHECK(size(first) == 2);

    if (size(first) == 2)
    {
        BOOST_CHECK(fabs(first[0] - 3.57771) < 0.1);
        BOOST_CHECK(fabs(first[1] - 7.15542) < 0.1);
    }

    BOOST_CHECK(size(second) == 2);

    if (size(second) == 2)
    {
        BOOST_CHECK(fabs(second[0] - 8.69782) < 0.1);
        BOOST_CHECK(fabs(second[1] - 17.3956) < 0.1);
    }

    std::cout << "Finished SomeTest\n";
}

BOOST_AUTO_TEST_CASE(type_checks)
{
    std::cout << "Started SomeTest\n";

    BOOST_CHECK(std::is_class_v<Ufo>);
    BOOST_CHECK(std::is_class_v<Ballistic>);
    BOOST_CHECK(std::is_class_v<Vertical>);
    BOOST_CHECK(std::is_abstract_v<Ufo>);
    BOOST_CHECK(std::is_polymorphic_v<Ufo>);

    std::cout << "Finished SomeTest\n";
}

BOOST_AUTO_TEST_CASE(ballistic_after_one_flight)
{
    std::cout << "Started SomeTest\n";

    Ballistic ball("ball", 40.0, 60.0);
    ball.flyToDest(dest4[0], dest4[1], dest4[2], 5);
    BOOST_CHECK(size(ball.getPosition()) == 3);

    if (size(ball.getPosition()) == 3)
    {
        BOOST_CHECK(fabs(ball.getPosition()[0] - dest4[0]) < 0.2);
        BOOST_CHECK(fabs(ball.getPosition()[1] - dest4[1]) < 0.2);
        BOOST_CHECK(ball.getPosition()[2] == 0.0);
        
        std::cout << "Finished SomeTest\n";
    }

    BOOST_CHECK(fabs(ball.getFtime() - 20.8) < 3);

    std::vector<float> first = ball.firstWaypoint(dest1[0], dest1[1], dest1[2]);
    std::vector<float> second = ball.secondWaypoint(dest1[0], dest1[1], dest1[2]);

    BOOST_CHECK(size(first) == 2);

    if (size(first) == 2)
    {
        BOOST_CHECK(fabs(first[0] - (-1.47772)) < 0.2);
        BOOST_CHECK(fabs(first[1] - 4.26277) < 0.2);
    }

    BOOST_CHECK(size(second) == 2);

    if (size(second) == 2)
    {
        BOOST_CHECK(fabs(second[0] - 5.86826) < 0.1);
        BOOST_CHECK(fabs(second[1] - 7.93552) < 0.1);
    }

    first = ball.firstWaypoint(dest6[0], dest6[1], dest6[2]);
    second = ball.secondWaypoint(dest6[0], dest6[1], dest6[2]);

    BOOST_CHECK(size(first) == 2);

    if (size(first) == 2)
    {
        BOOST_CHECK(fabs(first[0] - (-11.9881)) < 0.2);
        BOOST_CHECK(fabs(first[1] - (-2.97532)) < 0.2);
    }

    BOOST_CHECK(size(second) == 2);

    if (size(second) == 2)
    {
        BOOST_CHECK(fabs(second[0] - (-19.0396)) < 0.1);
        BOOST_CHECK(fabs(second[1] - (-13.5586)) < 0.1);
    }
}

BOOST_AUTO_TEST_SUITE_END()