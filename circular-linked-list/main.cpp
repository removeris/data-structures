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
		circularLinkedList()  //konstruktorius 
			{
				tail = nullptr;
			}
			
		void addNodeEnd(int value)
		{
			node* temp = new node;

            temp->data = value;
            if(tail == nullptr){
                tail = temp;
                tail->next = tail;
            }
            else {
                temp->next = this->tail->next;
                tail->next = temp;
                tail = temp;
            }
		}
		
		void display()
		{
            node* temp = tail;

            temp->next = this->tail;

            while(temp->next != tail){
                std::cout << temp->data;
            }

            if(size - pos > pos)
		}
		
		void addNodeStart(int value)
		{



		}
		void addNodePos(int pos, int value)
		{
            
		}

	// nepamirsti kitu funkciju ir destruktoriaus
};

int main()
{
	circularLinkedList listas;
	listas.addNodeEnd(25);
	listas.addNodeEnd(10);
	listas.addNodeEnd(3);
	listas.addNodeEnd(125);
	listas.display();
    std::cin.get();
    return 0;
}
