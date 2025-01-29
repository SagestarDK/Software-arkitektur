#include <iostream>
#include "AbstractQueue.h"
#include <stdexcept>

using namespace std;

class Node {
public:
    int data;     // Data held by the node
    Node* next;   // Pointer to the next node

    // Constructor to initialize the node
    Node(int value) : data(value), next(nullptr) {}
};

class list_int_Queue : public AbstractQueue {
private:
    Node* front;         // Pointer to the front of the queue
    Node* rear;          // Pointer to the rear of the queue
    size_t currentSize;  // Number of elements in the queue

public:
    // Constructor
    list_int_Queue() : front(nullptr), rear(nullptr), currentSize(0) {}

    // Destructor to clean up the queue
    ~list_int_Queue(){
        while (!empty()) {
            dequeue();  // Remove all nodes
        }
    }

    void enqueue(int a) override{
            Node* newNode = new Node(a);  // Create a new node
            // Ryk rear fremad, wrap manuelt.
            if (empty()) {
                front = rear = newNode;  // If empty, both front and rear point to the new node
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        currentSize++;
        }

    int dequeue() override{
        if (empty()) {
            throw std::underflow_error("Queue is empty");
            return -1; // kan ikke fjerne elementer hvis den er tom
        }
        else{
            Node* temp = front;          // Temporarily store the front node so we can free the element later
            int value = front->data;     // Få data fra front noden.
            front = front->next;         // Ryk front pointeren til den næste node.
            delete temp;                 // Free memory af vores node som vi fjerner
            if (!front){                 // Reset vores rear til nullptr, som er "enden" af vores node.
                rear = nullptr;
            }
            currentSize--;
            return value; 
        }
    }

    bool empty() const override{
        return front == nullptr; // hvis queue er tom så skal vores front være ligmed nullpointeren 
    }

    bool full() const override{
        return false; // list baseret på queue kan aldrig være fuld så længe der er lagerplads på computer
    }
    
    size_t size() const {
        return currentSize; // giver os mængden af elementer i queue
    }
};