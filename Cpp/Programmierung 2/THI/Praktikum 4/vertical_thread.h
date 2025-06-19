#include <thread>

#ifndef VERTICAL_THREAD_H
#define VERTICAL_THREAD_H

using namespace std;


class VerticalThread {
    private:
        thread* flyThread;
        Vertical* vert;
        bool isVertFlying;
    
    public:
        VerticalThread() {};
        ~VerticalThread() {};
        void runner(const float x, const float y, const float height, const int speed);
        void startUfo(const float x, const float y, const float height, const int speed);
        const bool getIsVertFlying();
};

#endif // VERTICAL_THREAD_H