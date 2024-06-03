#include <iostream>
using namespace std;
#define size 100
class Queue
{
private:
    int front = -1, rear = -1;
    int arr[size];

public:
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (rear == size - 1)
            return true;
        else
            return false;
    }
    void enQueue(int val)
    {
        if (isFull())
            cout << "Queue Overflow\n";
        else if (isEmpty())
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else
        {
            arr[++rear] = val;
        }
    }
    void deQueue()
    {
        if (isEmpty())
            cout << "Queue Underflow\n";
        else if (front == rear) // عشان ارجعه كيو فاضي لو فيه عنصر واحد بس
            front = rear = -1;
        else
            front++;
    }
    void front_val()
    {
        if (!isEmpty())
            cout << "Front element is :" << arr[front] << "\n";
        else
            cout << "Queue is empty \n";
    }
};

int main()
{
    Queue qu;
    qu.enQueue(2);
    qu.enQueue(8);
    qu.enQueue(3);
    qu.enQueue(5);
    qu.enQueue(4);
    while (!qu.isEmpty())
    {
        qu.front_val();
        qu.deQueue();
    }
    cout << qu.isEmpty() << "\n";
    cout << qu.isFull();
};
