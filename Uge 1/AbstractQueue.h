#include <iostream>

class AbstractQueue {

public:
virtual void enqueue(int value) = 0;    // Pure virtual
virtual int dequeue() = 0;              // Pure virtual
virtual bool empty() const = 0;         // Pure virtual
virtual bool full() const = 0;          // Pure virtual
virtual ~AbstractQueue() = default;     // Virtuel destruktor

};