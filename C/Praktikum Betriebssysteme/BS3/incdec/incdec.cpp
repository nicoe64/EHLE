#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <semaphore.h>

const size_t MAX_CNT = 10000000;
int a = 0;
// std::mutex mtx;
//sem_t sem;

void increment() {
    for(size_t i = 0; i<MAX_CNT; i++) {
        // std::lock_guard<std::mutex> lock(mtx);
        // sem_wait(&sem);
        a++;
        // sem_post(&sem);
    }
}

void decrement() {
    for(size_t i=0 ; i<MAX_CNT; i++) {
        // std::lock_guard<std::mutex> lock(mtx);
        // sem_wait(&sem);
        a--;
        // sem_post(&sem);
    }
}

int main() {

    // sem_init(&sem, 0, 1);

    std::thread Thread1(increment);
    std::thread Thread2(decrement);

    Thread1.join();
    Thread2.join();

    std::cout << "Final value of a: " << a << "\n";

    // sem_destroy(&sem);
    
    return 0;
}