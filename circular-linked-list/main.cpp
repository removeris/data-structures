#include <iostream>

struct node
{
	int data;
	node *next;	
};

class circularLinkedList
{
	private:
		node *tail;
    
	public:
		circularLinkedList() {
				tail = nullptr;
		}
		~circularLinkedList() {
		}
			
		void addNodeEnd(int value)
		{
			node* new_node = new node;
			new_node->data = value;

			if(isEmpty()) {
				new_node->next = new_node;
				tail = new_node;
			}
			else {
				new_node->next = tail->next;
				tail->next = new_node;
				tail = new_node;
			}
			
		}
		
		void addNodeStart(int value)
		{
			node* new_node = new node;
			new_node->data = value;
			
			if(isEmpty()) {
				tail = new_node;
				tail->next = tail;
			}
			else {
				node* temp = tail;
				while(temp != tail){
					temp = temp->next;
				}

				new_node->next = tail->next;
				tail->next = new_node;
			}
		}
		void addNodePos(int pos, int value)
		{
			node* new_node = new node;
			new_node->data = value;

           	if(isEmpty()) {
				tail = new_node;
				tail->next = tail;
		   	}
			else {
				node* travelling_ptr = tail->next;
				for(int i = 1; i < pos - 1; i++){
					travelling_ptr = travelling_ptr->next;
				}

				new_node->next = travelling_ptr->next;
				travelling_ptr->next = new_node;
				if(travelling_ptr == tail) {
					tail = new_node;
				}
			} 
		}

		bool isEmpty() {
			return tail == nullptr;
		}

		void deleteNodeStart() {
			if(isEmpty()){
				std::cout << "Deletion unavailable: empty list\n";
				return;
			}

			if(tail->next == tail){
				delete tail;
				tail = nullptr;
			}
			else {
				node* temp = tail->next;
				tail->next = tail->next->next;
				delete temp;
			}
		}

		void deleteNodeEnd(){
			if(isEmpty()){
				std::cout << "Deletion unavailable: empty list.\n";
				return;
			}
			// 1 element
			
			if(tail->next == tail){
				delete tail;
				tail = nullptr;
			}
			else {
				node* travelling_ptr = tail;

				while(travelling_ptr->next != tail) {
					travelling_ptr = travelling_ptr->next;
				}

				node* temp = tail;

				travelling_ptr->next = tail->next;
				tail = travelling_ptr;
				delete temp;
			}
		}

			void deleteNodePos(int pos) {
				if(isEmpty()){
					std::cout << "Deletion unavailable: empty list\n";
					return;
				}

				if(tail->next == tail) {
					delete tail;
					tail = nullptr;
				}
				else {
					node* travelling_ptr = tail->next;

					for(int i = 1; i < pos - 1; i++){
						travelling_ptr = travelling_ptr->next;
					}

					node* temp = travelling_ptr->next;
					if(temp == tail){
						tail = travelling_ptr;
						delete temp;
					}
					else {
						travelling_ptr->next = temp->next;
						delete temp;
					}
				}
			}

			void search (int value) {
				if(isEmpty()){
					std::cout << "Search unavailable: list is empty.\n";
					return;
				}
				int idx = 1;

				node* travelling_ptr = tail->next;

				std::cout << "Value " << value << "can be found at indexes: ";
				
				while(travelling_ptr != tail){
					if(travelling_ptr->data == value){
						std::cout << idx << " ";
					}
					idx++;
					travelling_ptr = travelling_ptr->next;
				}
				if(tail->data == value)
					std::cout << idx;
				std::cout << "\n";
			}

			void display(){
				node* travelling_ptr = tail->next;
				if(isEmpty()){
					std::cout << "Display unavailable: list is empty!\n";
					return;
				}
				
				std::cout << "List:\n";

				while(travelling_ptr != tail){
					std::cout << travelling_ptr->data << " ";
					travelling_ptr = travelling_ptr->next;
				}
				std::cout << tail->data << "\n";
		}


};

int main()
{
	circularLinkedList listas;
	listas.addNodeEnd(25);
	listas.addNodeEnd(10);
	listas.addNodeEnd(3);
	listas.addNodeEnd(125);
	listas.display();
	listas.deleteNodeEnd();
	listas.display();
	listas.deleteNodeStart();
	listas.display();
	listas.addNodePos(1, 5);
	listas.addNodeEnd(5);
	listas.display();
	listas.search(5);
    return 0;
}
