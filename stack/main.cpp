#include <iostream>

const int MAX_SIZE = 300;

class Stack {
    private:

        int top; // Top element index
        int array[MAX_SIZE]; // Stack static array
    
    public:

    Stack() {
        this->top = -1;
    }

    void push(int value) {
        if(isFull()) {
            std::cout << "Stack is full";
        }
        else {
            top++;
            array[top] = value;
        }
    }

    void pop() {
        if(isEmpty()){
            std::cout << "Stack is empty";
        }
        else {
            array[top] = 0;
            top--;
        }
    }

    void peek() {
        if(isEmpty()){
            std::cout << "Stack is empty";
        }
        else {
            std::cout << array[top] << "\n";
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void display(Stack stack) {
        while(!stack.isEmpty()) {
            stack.peek();
            stack.pop();
        }
    }

};

int main() {

    Stack stack;

    std::cout << stack.isEmpty() << "\n";
    std::cout << stack.isFull() << "\n";

    stack.push(8);
    stack.push(5);

    stack.peek();

    stack.pop();
    
    stack.peek();

    std::cout << stack.isEmpty() << "\n";

    stack.push(2);
    stack.push(8);
    stack.push(6);

    stack.display(stack);

    return 0;
}