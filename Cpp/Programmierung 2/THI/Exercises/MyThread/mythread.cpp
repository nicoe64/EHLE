#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

class Worker {
    private:
        int number;
        int countdown;
        thread workerThread;

        void run() {
        cout << "\nWorker Thread" << number << " started\n";

        for(; countdown >= 0; countdown--) {
            cout << number << " ";
            this_thread::sleep_for(chrono::milliseconds(300));
        }
        cout << "\nmyThread terminated\n";
    }
    public:
    
    Worker(const int pNumber, const int pCountdown) {
        number = pNumber;
        countdown = pCountdown;
        workerThread = thread([this]{run();});
    }
    ~Worker() {
        workerThread.join();
    }
};

int main() {
    Worker worker1 (1, 50);     // Erste Zahl ist die Nummer, zweite ist der Countdown
    this_thread::sleep_for(chrono::milliseconds(300));

    Worker worker2 (2, 10);
    this_thread::sleep_for(chrono::milliseconds(300));

    Worker worker3 (3, 20);
    this_thread::sleep_for(chrono::milliseconds(300));
}