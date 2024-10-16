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
            while(!isEmpty()){
                deleteNodeStart();
            }
        }

        void addNodeStart(int value) {
            Node* new_node = new Node;
            new_node->data = value;

            if(isEmpty()) {
                new_node->prev = new_node;
                new_node->next = new_node;
                tail = new_node;
            }
            else {
                new_node->prev = tail;
                new_node->next = tail->next;
                tail->next = new_node;
            }
        }

        void addNodePosition(int value, int idx) {
            Node* new_node = new Node;
            new_node->data = value;
            
            Node* travelling_ptr;

            while(idx > size) {
                idx -= size;
            }
            if(isEmpty()) {
                new_node->next = new_node;
                new_node->prev = new_node;
                tail = new_node;
                return;
            }
            else if(size - idx < idx) {
                travelling_ptr = tail->prev;

                for(int i = size - idx; i > 1; i--){
                    travelling_ptr = travelling_ptr->prev;
                }
            }
            else {
                travelling_ptr = tail->next;

                for(int i = 1; i < idx; i++) {
                    travelling_ptr = travelling_ptr->next;
                }
            }

            travelling_ptr->prev->next = new_node;
            new_node->next = travelling_ptr;
            travelling_ptr->prev = new_node;
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
            if(isEmpty()) {
                std::cout << "Circular doubly linked list is empty!\n";
                return;
            }
            // 1 elem
            else if(tail->next == tail) {
                delete tail;
                tail = nullptr;
            }
            else {
                Node* temp = tail->next;

                temp->next->prev = tail;
                tail->next = tail->next->next;

                delete temp;
            }
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
            if(isEmpty()) {
                std::cout << "Circular doubly linked list is empty!\n";
                return;
            }
            else if(tail->next == tail) {
                delete tail;
                tail = nullptr;
            }
            else {
                Node* temp = tail;
                
                tail->prev->next = tail->next;
                tail->next->prev = tail->prev;

                tail = tail->prev;

                delete temp;
            }
        }

        void display() {
            if(isEmpty()){
                std::cout << "Circular doubly linked list is empty!\n";
                return;
            }   
            Node* travelling_pointer = tail->next;

            std::cout << "List: ";
            while(travelling_pointer != tail){
                std::cout << travelling_pointer->data << " ";
                travelling_pointer = travelling_pointer->next;
            }

            std::cout << travelling_pointer->data << "\n";
        }

        bool isEmpty() {
            return tail == nullptr;
        }

        void search(int value) {
            if(isEmpty()){
                std::cout << "Circular doubly linked list is empty!\n";
                return;
            }   

            Node* travelling_pointer = tail->next;
            int index = 1;

            std::cout << "Value " << value << " can be found at index(-es): ";
            while(travelling_pointer != tail){
                if(travelling_pointer->data == value){
                    std:: cout << index << "";
                }
                travelling_pointer = travelling_pointer->next;
                index++;
            }
            if(travelling_pointer->data == value){
                std::cout << index << "\n";
                return;
            }
            std::cout << "\n";
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
    list.addNodePosition(86, 7);

    list.deleteNodeStart();

    list.deleteNodeEnd();

    list.display();

    list.search(7);

    return 0;
}