#include <iostream>

const int MAX_SIZE = 300;

class Queue {
    private:
        int front;
        int back;
        int array[MAX_SIZE];
    public:
        Queue() {
            this->front = -1;
            this->back = -1;
        }

        // Add elements to back
        void enqueue(int value) {
            if(isFull()){
                std::cout << "Queue is full!";
            }
            else if(isEmpty()) {
                this->front++;
                this->back++;
                this->array[this->back] = value;
            }
            else {
                this->back++;
                this->array[this->back] = value;
            }
        }

        // Remove elements from front
        void dequeue() {
            if(isEmpty()){
                std::cout << "Queue is empty.\n";
            }
            else {
                this->front++;
            }
        }

        // Display front value
        void frontDisplay() {
            if(isEmpty()) {
                std::cout << "Queue is empty.\n";
            }
            else {
                std::cout << this->array[this->front] << " index " << this->front << "\n";
            }
        }

        // Display back value
        void backDisplay() {
            if(isEmpty()) {
                std::cout << "Queue is empty.\n";
            }
            else {
                std::cout << this->array[this->back] << " index " << this->back << "\n";
            }
        }

        bool isEmpty() {
            return this->front == -1 || this->front > this->back;
        }

        bool isFull() {
            return (this->back == MAX_SIZE - 1 && this->front != 0);
        }
};

void fullDisplay(Queue queue){
    std::cout << "Empty? " << queue.isEmpty() << "\n";
    std::cout << "Full? " << queue.isFull() << "\n";
    std::cout << "Front:";
    queue.frontDisplay();
    std::cout << "Back:";
    queue.backDisplay();
    std::cout << "\n";
}

int main() {
    Queue queue;

    queue.enqueue(4);
    fullDisplay(queue);

    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(-3);
    fullDisplay(queue);

    queue.dequeue();
    fullDisplay(queue);

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    fullDisplay(queue);

    return 0;
}