#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(){
        next = nullptr;
    }
    Node(int value, Node* ptr){
        this->data = value;
        this->next = ptr;
    }
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        ~LinkedList() {
            Node* temp = head;

            while(temp != nullptr) {
                Node* current = temp;
                temp = temp->next;
                delete current;
            }

            head = nullptr;
            tail = nullptr;

            std::cout << "Destructor successful.\n";
        }

        void addNodeStart(int value) {
            Node* new_node = new Node;
            new_node->data = value;
            
            if(isEmpty()){
                tail = new_node;
            }
            else {
                new_node->next = head;
            }
            
            head = new_node; 
        }
        
        void addNodePosition(int value, int idx) {
            Node* new_node = new Node;
            new_node->data = value;

            // Travelling pointer
            Node* temp = head;

            for(int i = 1; i < idx - 1; i++) {
                temp = temp->next;
            }

            // Travelling pointer at desired pos

            new_node->next = temp->next;
            temp->next = new_node;

            if(idx == 1){
                head = new_node;
            }
        }

        void addNodeEnd(int value) {
            Node* new_node = new Node;
            new_node->data = value;
            new_node->next = nullptr;

            tail->next = new_node;
            tail = new_node;
        }

        void deleteNodeStart() {
            if(isEmpty()){
                std::cout << "Deletion Unavailable: Linked list is empty!\n";
                return;
            }

            if(head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else {
                Node* temp = head;
                head = temp->next;

                delete temp;
            }
        }

        void deleteNodePosition(int idx) {
            if(isEmpty()){
                std::cout << "Deletion Unavailable: Linked List is empty";
                return;
            }

            // Travelling pointer
            Node* temp = head;

            for(int i = 1; i < idx - 1; i++){
                if(temp->next == nullptr){
                    std::cout << "Invalid index: Out of range";
                    return;
                }
                temp->next = temp;
            }

            // Hold reference to removable node
            Node* temp2 = temp->next;

            temp->next = temp->next->next;
            delete temp2;
        }

        void deleteNodeEnd() {
            if(isEmpty()) {
                std::cout << "Deletion unavailable: Linked list is empty!\n";
                return;
            }

            if(head == tail){
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else {
                // Travelling pointer
                Node* temp = head;

                while(temp->next->next != nullptr) {
                    temp = temp->next;
                }

                delete temp->next;
                tail = temp;
                tail->next = nullptr;
            }
        }

        void search(int value) {
            
            if(isEmpty()){
                std::cout << "Search Unavailable: Linked list is empty!\n";
                return;
            }

            Node* temp = head;
            
            int idx = 1;

            std::cout << value << " is in pos: ";

            while(temp != nullptr){
                if(temp->data == value){
                    std::cout << idx << " ";
                }
                temp = temp->next;
                idx++;
            }

            std::cout << "\n";
        }

        bool isEmpty() {
            return head == nullptr;
        }

        void display() {
            if(isEmpty()){
                std::cout << "Display Unavailable: Linked list is empty!\n";
                return;
            }
            Node* temp = head;
            
            std::cout << "List: ";
            while(temp != nullptr){
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << "\n";
        }

        void reverse() {
            if(isEmpty()){
                std::cout << "Reversal unavailable: Linked list is empty!\n";
                return;
            }

            tail = head;
            Node* temp_next;
            Node* temp_current = head;
            Node* temp_prev = nullptr;

            while(temp_current != nullptr){
                temp_next = temp_current->next;
                temp_current->next = temp_prev;

                temp_prev = temp_current;
                temp_current = temp_next;
            }

            head = temp_prev;
        }
};

int main() {
    LinkedList list;

    list.addNodeStart(5);
    list.addNodeEnd(3);
    list.addNodePosition(86, 2);
    list.addNodePosition(34, 3);
    list.addNodeEnd(5);
    list.display();

    list.search(34);

    list.deleteNodeEnd();
    list.display();

    list.addNodePosition(7, 1);
    list.display();

    list.deleteNodeStart();
    list.deleteNodeStart();
    list.deleteNodeStart();
    list.deleteNodeStart();
    list.search(3);
    list.display();

    list.addNodeStart(50);
    list.addNodeStart(37);
    list.addNodePosition(98, 2);
    list.addNodeEnd(74);
    list.display();

    list.reverse();
    list.display();

    list.deleteNodePosition(2);
    list.display();
    //list.display();


    return 0;
}