#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class CircularDoublyLinkedList {
    private:
        Node* tail;
        int size;
    public:
        CircularDoublyLinkedList() {
            tail = nullptr;
            size = 0;
        }
        ~CircularDoublyLinkedList() {

        }

        void addNodeStart(int value) {
            Node* new_node = new Node;

        }

        void addNodePosition(int value, int idx) {
            
        }

        void addNodeEnd(int value) {
            Node* new_node = new Node;
            new_node->data = value;

            if(isEmpty()) {
                new_node->next = new_node;
                new_node->prev = new_node;
            }
            else {
                new_node->prev = tail;
                new_node->next = tail->next;
                tail->next->prev = new_node;
                tail->next = new_node;
            }
            tail = new_node;
            size++;

        }

        void deleteNodeStart() {
            
        }

        void deleteNodePosition(int idx) {
            if(isEmpty()){
                std::cout << "Circular doubly linked list is empty!\n";
                return;
            }
            else {
                Node* travelling_ptr;
                
                while(idx > size) {
                    idx -= size;
                }

                if(size - idx < idx){
                    travelling_ptr = tail->prev;

                    for(int i = size - idx; i > 1; i--){
                        travelling_ptr = travelling_ptr->prev;
                    }
                }
                else{
                    travelling_ptr = tail->next;

                    for(int i = 1; i < idx; i++) {
                        travelling_ptr = travelling_ptr->next;
                    }
                }

                travelling_ptr->prev->next = travelling_ptr->next;
                travelling_ptr->next->prev = travelling_ptr->prev;

                // 1 Element in list
                if(tail->next == tail) {
                    tail = nullptr;
                }
                else if(travelling_ptr == tail) {
                    tail = travelling_ptr->prev;
                }

                delete travelling_ptr;
            }
        }

        void deleteNodeEnd() {

        }

        void display() {
            if(isEmpty()){
                std::cout << "Circular doubly linked list is empty!\n";
                return;
            }   
            Node* travelling_pointer = tail->next;
            int n = 1;

            while(travelling_pointer != tail){
                n++;
                travelling_pointer = travelling_pointer->next;
            }

            travelling_pointer = tail->next;

            std::cout << "List: ";
            for(int i = 0; i < n; i++){
                std::cout << travelling_pointer->data << " ";
                travelling_pointer = travelling_pointer->next;
            }

            std::cout << "\n";
        }

        bool isEmpty() {
            return tail == nullptr;
        }
};

int main() {
    CircularDoublyLinkedList list;

    list.addNodeEnd(3);
    list.addNodeEnd(8);
    list.addNodeEnd(4);
    list.addNodeEnd(7);
    list.addNodeEnd(9);
    list.addNodeEnd(11);

    for(int i = 0; i < 50; i++){
        list.addNodeEnd(i);
    }

    list.deleteNodePosition(40);
    
    list.addNodeEnd(1);

    list.display();

    return 0;
}