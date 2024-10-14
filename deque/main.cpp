#include <iostream>

const int MAX_SIZE = 10;

class Deque {
    private:
        int array[MAX_SIZE];
        int front;
        int rear;

    public:

        Deque() {
            front = -1;
            rear = -1;
        }
        void pushBack(int value) {
            if(isFull()){
                std::cout << "Deque is full!\n";
                return;
            }
            else if(isEmpty()) {
                front = 0;
                rear = 0;
            }
            // Rear reached max size, reset back to first elem
            else if(rear == MAX_SIZE - 1) {
                rear = 0;
            }
            else {
                rear++;
            }

            array[rear] = value;
        }

        void pushFront(int value) {
            if(isFull()){
                std::cout << "Deque is full!\n";
                return;
            }
            else if(isEmpty()) {
                front = 0;
                rear = 0;
            }
            else if(front == 0) {
                front = MAX_SIZE - 1;
            }
            else {
                front--;
            }
            
            array[front] = value;
        }

        void popFront() {
            if(isEmpty()) {
                std::cout << "Deque is empty!\n";
                return;
            }

            if(front == rear){
                front = -1;
                rear = -1;
            }
            else if(front == MAX_SIZE - 1) {
                front = 0;
            }
            else{
                front++;
            }            
        }

        void popBack() {
            if(isEmpty()){
                std::cout << "Deque is empty!\n";
                return;
            }
            else if(rear == 0){
                rear = MAX_SIZE - 1;
            }
            else if(rear == front) {
                front = -1;
                rear = -1;
            }
            else {
                rear--;
            }
        }

        int getFront() {
            if(isEmpty()){
                std::cout << "Deque is empty!\n";
                return - 1;
            }
            return array[front];
        }

        int getRear() {
            if(isEmpty()){
                std::cout << "Deque is empty!\n";
                return -1;
            }
            return array[rear];
        }

        bool isEmpty() {
            return front == -1;
        }

        bool isFull() {
            return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
        }
};

void dequeDisplay(Deque &deque) {
    int temp = deque.getFront();
    deque.popFront();
    deque.pushBack(temp);
    std::cout << temp << " ";
}

int main() {
    Deque deque;

    deque.pushBack(5);
    deque.pushFront(3);
    deque.pushBack(7);
    deque.pushBack(9);
    deque.pushFront(2);

    for(int i = 0; i < 5; i++){
        dequeDisplay(deque);
    }

    std::cout << "\n";

    deque.popFront();
    deque.popBack();

    for(int i = 0; i < 3; i++){
        dequeDisplay(deque);
    }


    return 0;
}