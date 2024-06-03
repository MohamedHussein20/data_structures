// Problems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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

	void Display()  //Travers & Display
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
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

	void insertLast(int item)
	{
		if (isEmpty())
		{
			InsertFirst(item);
		}

		else
		{
			Node* temp = head;
			while (temp->next!= NULL)
			{
				temp = temp->next;
			}
			Node* newnode = new Node();
			newnode->data = item;
			temp->next = newnode;
			newnode->next = NULL;
		}
	}



};
int main()
{
	LinkedList lst;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int n;
		cin >> n;
		lst.InsertFirst(n);
	}
	lst.Display();
}
