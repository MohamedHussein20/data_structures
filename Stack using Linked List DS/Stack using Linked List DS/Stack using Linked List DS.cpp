#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node()
	{
		data = 0;
		next = NULL;
	}
};
class Stack
{
	Node* Top;
public:

	Stack()
	{
		Top = NULL;
	}

	bool isEmpty()
	{
		if (Top==NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void push(int item)
	{
		Node* newnode = new Node();
		newnode->data = item;

		if (isEmpty())
		{
			newnode->next = NULL;
			Top = newnode;
		}

		else
		{
			newnode->next = Top;
			Top = newnode;

		}
	}

	void pop()
	{
		Node* delptr = Top;
		Top = Top->next;
		delete delptr;
	}

	void display()
	{
		Node* temp = Top;
		while (temp!=NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	int top()
	{
		return Top->data;
	}

	int count()
	{
		int counter = 0;
		Node* temp = Top;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}

	bool isFound(int item)
	{
		bool found = false;
		Node* temp = Top;
		while (temp != NULL)
		{
			if (temp->data==item)
			{
				found = true;
			}
			temp = temp->next;
		}
		return found;
	}

	bool isFull()
	{
		Node* ptr = new Node();
		if (ptr==NULL)
		{
			cout << "The stack is full " << endl;
		}
	}


};
int main()
{
	Stack s;
	int item;
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter an item to push " << endl;
		cin >> item;
		s.push(item);
	}
	cout << "Enter item to search for " << endl;
	cin >> item;
	if (s.isFound(item))
	{
		cout << "found" << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
	cout << s.count() << endl;
	return 0;
}