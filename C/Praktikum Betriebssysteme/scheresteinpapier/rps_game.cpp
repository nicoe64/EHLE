#include <iostream>
#include <thread>
#include <random>
#include <mutex>

std::mutex mtx;

int spieler1_wins = 0;
int spieler2_wins = 0;

enum class Zeichen {
    SCHERE,
    STEIN,
    PAPIER
};

Zeichen zufaelligesZeichen() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);

    return static_cast<Zeichen>(dis(gen));
}

void spieler1thread() {
    while (true) {
        mtx.lock();
        if (spieler1_wins >= 3 || spieler2_wins >= 3) {
            mtx.unlock();
            break;
        }
        Zeichen spieler1Geste = zufaelligesZeichen();
        mtx.unlock();
    }
}

void spieler2thread() {
    while (true) {
        mtx.lock();
        if (spieler1_wins >= 3 || spieler2_wins >= 3) {
            mtx.unlock();
            break;
        }
        Zeichen spieler2Geste = zufaelligesZeichen();
        mtx.unlock();
    }
}

void schirithread() {
    int runden = 0;
    while (spieler1_wins < 3 && spieler2_wins < 3 && runden < 50) {
        mtx.lock();
        Zeichen spieler1Geste = zufaelligesZeichen();
        Zeichen spieler2Geste = zufaelligesZeichen();
        mtx.unlock();

        // Logik zur Bestimmung des Gewinners hier einfügen

        runden++;
    }
    if (spieler1_wins > spieler2_wins)
        std::cout << "Spieler 1 gewinnt!" << std::endl;
    else if (spieler2_wins > spieler1_wins)
        std::cout << "Spieler 2 gewinnt!" << std::endl;
    else
        std::cout << "Unentschieden!" << std::endl;

        // Logik zur Bestimmung des Gewinners hier einfügen

        runden++;
}

int main() {

    std::thread spieler1(spieler1thread);
    std::thread spieler2(spieler2thread);
    std::thread schiri(schirithread);

    spieler1.join();
    spieler2.join();
    schiri.join();
    
    return 0;
}
