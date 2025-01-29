#include <iostream>
#include "AbstractQueue.h"

using namespace std;

class Array_int_Queue : public AbstractQueue {
private:
    static const size_t MAX_SIZE = 5;  // Maximum size of the queue
    int data[MAX_SIZE];                // Fixed-size array to hold the elements
    int front;                         // Index af front/første element i array
    int rear;                          // Index af sidste element i array
    size_t currentSize;                // Current number of elements in the queue

public:
    // Constructor
    Array_int_Queue() : front(0), rear(-1), currentSize(0) {}

     // Destructor
    ~Array_int_Queue() override = default;

    void enqueue(int a) override{
        // Check om køen er tom inden vi tilføjer element
        if (full()){
            throw std::overflow_error("Queue is full");
        }
        // Ryk rear fremad, wrap manuelt.
        if (rear + 1 == MAX_SIZE) {
            rear = 0;  // Wrap around
        } else {
            rear++;
        }
        data[rear] = a;  // Sæt nyt element "a" ind i kø
        currentSize++;
        }

    int dequeue() override{
        if (empty()) { // kan ikke fjerne elementer fra en tom kø
            throw std::underflow_error("Queue is empty");
        }
        int a = data[front];  // Få front a
        // Move `front` forward, wrapping manually
        if (front + 1 == MAX_SIZE) {
            front = 0;  // Wrap around
        } else {
            front++;
        }
        currentSize--;
        return a;
    }

    bool empty() const override{
        return currentSize == 0;
    }

    bool full() const override{
        return currentSize == MAX_SIZE; 
    }

    size_t size() const{ 
        return currentSize; // giver os mængden af elementer i queue
    }
};