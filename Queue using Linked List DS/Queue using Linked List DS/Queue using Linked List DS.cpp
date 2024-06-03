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

class Queue
{
public:
    Node* Front;
    Node* Back;
    Queue()
    {
        Front = Back = NULL;
    }

    bool isEmpty()
    {
        if (Front == NULL)
        {
            return true;
        }
        
        else
        {
            return false;
        }
    }

    void Push(int item)
    {
        if (isEmpty())
        {
            Node* newnode = new Node();
            newnode->data = item;
            Front = Back = newnode;
        }

        else
        {
            Node* newnode = new Node();
            newnode->data = item;
            Back->next = newnode;
            Back = newnode;
        }
        
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "The Queue is Empty " << endl;
        }
        else
        {
            Node* temp = Front;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "The queue is Empty " << endl;
        }
        else if (Front == Back)
        {
            delete Front;
            Front = Back = NULL;
        }
        else
        {
            Node* delptr;
            delptr = Front;
            Front = Front->next;
            delete delptr;
        }        
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "The Queue is Empty " << endl;
        }
        else
        {
            return Front->data;
        }
    }

    int back()
    {
        if (isEmpty())
        {
            cout << "The Queue is Empty " << endl;
        }
        else
        {
            return Back->data;
        }
    }

    int count()
    {
        int counter = 0;
        Node* temp = Front;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
    }

    bool isFound(int item)
    {
        bool found = false;
        Node* temp = Front;
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

    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

};

int main()
{
    Queue q;
    int x;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter item to enqueue " << endl;
        cin >> x;
        q.Push(x);
    }
    q.clear();
    q.display();
    return 0;
}