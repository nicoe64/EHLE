#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define PRODUCE_COUNT 5

/**Listenfunktionen */

// Struktur eines Knotens der verketteten Liste
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Struktur der verketteten Liste
typedef struct {
    Node* head;
    Node* tail;
    sem_t sem_mutex;
    sem_t sem_full;
    int size;
} LinkedList;

// Funktion zum Erstellen einer neuen verketteten Liste
LinkedList* createList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    sem_init(&list->sem_mutex, 0, 1);
    sem_init(&list->sem_full, 0, 0);
    list->size = 0;
    return list;
}

// Funktion zum Hinzufügen eines Elements am Anfang der Liste
void addElement(LinkedList* list, int data) {
    sem_wait(&list->sem_mutex);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    if (list->tail == NULL) {
        list->tail = newNode;
    }
    list->size++;
    sem_post(&list->sem_full);
    sem_post(&list->sem_mutex);
}

// Funktion zum Entfernen eines Elements am Ende der Liste
int removeElement(LinkedList* list) {
    sem_wait(&list->sem_full);
    sem_wait(&list->sem_mutex);

    Node* temp = list->head;
    Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    int data = temp->data;
    if (prev == NULL) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        prev->next = NULL;
        list->tail = prev;
    }
    free(temp);
    list->size--;
    sem_post(&list->sem_mutex);
    return data;
}

// Funktion zum Freigeben der Liste
void freeList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    sem_destroy(&list->sem_mutex);
    sem_destroy(&list->sem_full);
    free(list);
}

/**Thread Funktionen */

// Zufallszahlengenerator initialisieren
void initRand() {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    srand((unsigned int)ts.tv_nsec);
}

// Funktion für den Producer-Thread
void* producer(void* arg) {
    LinkedList* list = (LinkedList*)arg;
    initRand();
    for (int i = 0; i < PRODUCE_COUNT; i++) {
        int data = rand() % 100;
        addElement(list, data);
        printf("Producer %ld: Added %d\n", (long)pthread_self(), data);
        // Arbeit simulieren
        struct timespec ts = {0, rand() % 1000000};
        nanosleep(&ts, NULL);
    }
    return NULL;
}

// Funktion für den Consumer-Thread
void* consumer(void* arg) {
    LinkedList* list = (LinkedList*)arg;
    initRand();
    for (int i = 0; i < PRODUCE_COUNT; i++) {
        int data = removeElement(list);
        printf("Consumer %ld: Removed %d\n", (long)pthread_self(), data);
        // Arbeit simulieren
        struct timespec ts = {0, rand() % 1000000};
        nanosleep(&ts, NULL);
    }
    return NULL;
}

/** Main Funktion */

int main() {

    int anz;
    printf("Anzahl producer/consumer: ");
    scanf("%d", &anz);

    LinkedList* list = createList();
    pthread_t producers[anz];
    pthread_t consumers[anz];

    // Producer-Threads starten
    for (int i = 0; i < anz; i++) {
        pthread_create(&producers[i], NULL, producer, list);
    }

    // Consumer-Threads starten
    for (int i = 0; i < anz; i++) {
        pthread_create(&consumers[i], NULL, consumer, list);
    }

    // Warten, bis alle Threads beendet sind
    for (int i = 0; i < anz; i++) {
        pthread_join(producers[i], NULL);
    }
    for (int i = 0; i < anz; i++) {
        pthread_join(consumers[i], NULL);
    }

    // Liste freigeben
    freeList(list);
    return 0;
}
