#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <cmath>
#include <atomic>

// TEST

std::mutex coutMutex;
// std::mutex currentNumberMutex;
// int current_number;
std::atomic<int> current_number;


bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
/*
void checkPrimes(int p) {
    while (true) {
        int num;
        {
            std::lock_guard<std::mutex> guard(currentNumberMutex);
            num = current_number++;
            if (num > p) return; // Exit condition
        }

        if (isPrime(num)) {
            std::lock_guard<std::mutex> guard(coutMutex);
            std::cout << num << " ist eine Primzahl\n";
        }
    }
}
*/
void checkPrimes(int p) {
    while (true) {
        // std::lock_guard<std::mutex> guard1(currentNumberMutex);
        int num = current_number++;
        if (num > p) return; // Exit condition

        if (isPrime(num)) {
            std::lock_guard<std::mutex> guard(coutMutex);
            std::cout << num << " ist eine Primzahl\n";
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

    for (int i = 0; i < t; ++i) {
        threads.push_back(std::thread(checkPrimes, p)); // p als Parameter übergeben
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
        Nanoseconds += static_cast<long>(pow(10, 9));
    }


    std::cout << "Sekunden: " << Seconds << "\n";
    std::cout << "Nanosekunden: " << Nanoseconds << "\n";
    
    return 0;
}