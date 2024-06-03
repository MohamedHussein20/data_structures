#include <iostream>
#include <algorithm>

using namespace std;
class Node
{
public:
	int data;
	Node* next;       // indicates to the next node
};


class LinkedList
{
public:
	Node* head;

	LinkedList()
	{
		head = NULL;
	}

	bool isEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}

	int count()
	{
		int c = 0;{}
		Node* temp = head;
		while (temp != NULL)
		{
			c++;
			temp = temp->next;
		}
		return c;
	}

	bool isFound(int key)
	{
		bool found = false;
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == key)
			{
				found = true;
				temp = temp->next;
			}
		}
		return found;
	}

	void InsertFirst(int newValue)
	{
		Node* newNode = new Node();
		newNode->data = newValue;
		if (isEmpty())
		{
			newNode->next = NULL;
			head = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}

	void InsertBefore(int item, int newValue)
	{
		if (isEmpty())
		{
			cout << "is empty" << endl;
			return;
		}

		if (head->data == item)
		{
			Node* newNode = new Node();
			newNode->data = newValue;
			newNode->next = head;
			head = newNode;
			return;
		}

		Node* current = head;
		while (current->next != NULL)
		{
			current->next->data == item;
			{
				Node* newNode = new Node();
				newNode->data = newValue;
				newNode->next = current->next;
				current->next = newNode;
				return;
		}
			current = current->next;
		}

		cout << "Item not found in the list." << endl;
	}

	void InsertLast(int newvalue)
	{
		if (isEmpty())
		{
			InsertFirst(newvalue);
		}
			Node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			Node* newnode = new Node();
			newnode->data = newvalue;
			temp->next = newnode;
			newnode->next = NULL;
		
	}

	void Delete(int item)
	{
		Node* delptr = head;
		if (isEmpty())
		{
			cout << "List is empty. " << endl;
		}
		else if (head->data==item)
		{
			
			head = head->next;
			delete delptr;
		}
		else
		{
			Node* prev = NULL;
			while (delptr->data!=item)
			{
				prev = delptr;
				delptr = delptr->next;
			}
			prev->next = delptr->next;
			delete delptr;
		}
	}

};
int main()
{
	LinkedList lst;
	lst.InsertFirst(40);
	lst.InsertLast(50);
	lst.InsertBefore(40, 30);
	lst.Display();
	return 0;
}