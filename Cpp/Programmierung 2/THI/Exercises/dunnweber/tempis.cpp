#include <iostream>


template<class T> 
T maxValue (const T& a, const T& b) {
    if (a > b) {
        return a;
    } else (b > a ) {
        return b;
    }
}

template <class S>
class SimplePair {
    private:
    S x, y;

    public:
    SimplePair(S xVal, S yVal) : x(xVal), y (yVal) {};

    S getFirst() {
        return x;
    }
    S getSecond() {
        return y;
    }
    S swap() {
        S i;
        i = y;
        y = x;
        x = i;
    }
}



