#include <iostream>
#include <string>

template <class T>
T maxOfThree(T a, T b, T c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    std::cout << maxOfThree(3, 7, 5) << std::endl;               // 7
    std::cout << maxOfThree(3.14, 2.71, 3.99) << std::endl;      // 3.99
    std::cout << maxOfThree(std::string("apple"), "zebra", "bat") << std::endl;  // zebra
}
