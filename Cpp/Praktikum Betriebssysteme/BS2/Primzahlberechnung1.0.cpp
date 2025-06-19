#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <cmath>

std::mutex coutMutex;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void checkPrimes(int start, int end) {
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            std::lock_guard<std::mutex> guard(coutMutex);
            // std::cout << i << " ist eine Primzahl\n";
        }
    }
}

int main() {
    int p; // Obere Granze
    int t; // Anzahl der Threads

    std::cout << "Bis wohin soll gezählt werden?\n";
    std::cin >> p;
    std::cout << "Wie viele Threads sollen erstellt werden?\n";
    std::cin >> t;
    std::cout << "\n";

    // Zeitmessung Start
    timespec startzeit;
    clock_gettime(CLOCK_REALTIME, &startzeit);

    std::vector<std::thread> threads;
    int range = p / t;
    int start = 1;

    for (int i = 0; i < t; ++i) {
    int end;
    if (i == t - 1) {
        end = p;
    } else {
        end = start + range - 1;
    }
        threads.push_back(std::thread(checkPrimes, start, end));
        start = end + 1;
    }

    for (auto& th : threads) {
        th.join();
    }
    
    // Zeitmessung Ende
    timespec endzeit;
    clock_gettime(CLOCK_REALTIME, &endzeit);

    long Seconds = endzeit.tv_sec - startzeit.tv_sec;
    long Nanoseconds = endzeit.tv_nsec - startzeit.tv_nsec;

    if ( Nanoseconds < 0) {
        Seconds--;
        Nanoseconds += pow(10, 9);
    }


    std::cout << "Sekunden: " << Seconds << "\n";
    std::cout << "Nanosekunden: " << Nanoseconds << "\n";
    
    return 0;
}