#include "Queuearray.h"
#include <iostream>

//TEST OF OUR PROGRAM THAT SHOWS IT WORKS :)
int main() {
    Array_int_Queue queue; // Instantiate the queue object

    // Use the queue object to call enqueue
    queue.enqueue(10);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(15);
    queue.enqueue(20);

    std::cout << "Queue size: " << queue.size() << std::endl;

    // Dequeue elements
    while (!queue.empty()) {
        std::cout << "Dequeue: " << queue.dequeue() << std::endl;
    }

    // Check if the queue is empty
    std::cout << "Queue is empty: " << std::boolalpha << queue.empty() << std::endl;
}