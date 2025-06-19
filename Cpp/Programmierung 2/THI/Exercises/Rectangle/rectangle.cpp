#include <iostream>
#include "rectangle.h"
using namespace std;

int Rectangle::number = 420;

Rectangle::Rectangle(const float pHeight, const float pWidth) {
    setHeight(pHeight);
    setWidth(pWidth);
}

Rectangle::Rectangle(const Rectangle& rect): Rectangle(rect.height, rect.width) {} // Copy-Konstruktor

void Rectangle:: setHeight(const float pHeight) {
    if (pHeight > 0.0)
        height = pHeight;
    else 
        height = 1.0;
}

void Rectangle:: setWidth(const float pWidth) {
    if (pWidth > 0.0)
        width = pWidth;
    else    
        width = 1.0;
}

float Rectangle::getHeight() const {
    return height;
}

float Rectangle::getWidth() const {
    return width;
}

float Rectangle::compArea() const {
    return height*width;
}

int main() {

    Rectangle rectA(2.5, 10.0);
    rectA.setHeight(5.0);

    cout << Rectangle::number << '\n';

    cout << "Rectangle A:" << '\n';
    cout << "Height: " << rectA.getHeight() << '\n';
    cout << "Width: " << rectA.getWidth() << '\n';
    cout << "Area: " << rectA.compArea() << "\n\n";

    Rectangle rectB{rectA};

    cout << "Rectangle B:" << '\n';
    cout << "Height: " << rectB.getHeight() << '\n';
    cout << "Width: " << rectB.getWidth() << '\n';
    cout << "Area: " << rectB.compArea() << '\n';

    return 0;
}