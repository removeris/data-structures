#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
        }
        ~DoublyLinkedList() {

        }

        void addNodeStart(int value) {
            Node* new_node = new Node;
            new_node->data = value;
            new_node->prev = nullptr;

            if(isEmpty()){
                new_node->next = nullptr;
                head = new_node;
                tail = new_node;
            }
            else {
                head->prev = new_node;
                new_node->next = head;
                head = new_node;
            }
        }

        void addNodePosition(int value, int idx) {
            if(idx = 1){
                addNodeStart(value);
                return;
            }
            else {
                
            }

            
        }

        void addNodeEnd(int value) {
            Node* new_node = new Node;
            new_node->data = value;
            new_node->next = nullptr;
            
            if(isEmpty()){
                new_node->prev = nullptr;
                head = new_node;
                tail = new_node;
            }
            else {
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
            }
        }

        void deleteNodeStart() {
            if(isEmpty()){
                std::cout << "Doubly linked list is empty!\n";
                return;
            }
            else if(head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else {
                Node* temp = head;
                head = temp->next;
                head->prev = nullptr;

                delete temp;
            }
        }

        void deleteNodePosition(int value, int idx) {

        }

        void deleteNodeEnd() {
            if(isEmpty()){
                std::cout << "Doubly linked list is empty!\n";
                return;
            }
            else if(head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else {
                Node* temp = tail;
                tail->prev->next = nullptr;
                tail = tail->prev;

                delete temp;
            }
        }

        void display() {

        }

        void check() {

        }


        bool isEmpty(){
            return head == nullptr;
        }
};

int main() {



    return 0;
}