#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
class Stack
{
	int top;
	int item[MAX_SIZE];
public:
	Stack()
	{
		top = -1;
	}
	void push(int i)
	{
		item[top] = i;
		if (top >= MAX_SIZE - 1)
		{
			cout << "Stack full on push" << endl;
		}
		else
		{
			top++;
			item[top] = i;
		}
	}
	bool isEmpty()
	{
		return top < 0;
	}
	void pop()
	{
		if (isEmpty())
		{
			cout << "stack empty on pop" << endl;
		}
		else
		{
			
			top--;
		}
	}
	void pop(int &i)
	{
		if (isEmpty())
		{
			cout << "stack empty on pop" << endl;
		}
		else
		{
			i = item[top];
			top--;
		}
	}
	void getTop(int& stackTop)
	{
		if (isEmpty())
		{
			cout << "stack empty on pop" << endl;
		}
		else
		{
			stackTop = item[top];
			cout << stackTop << endl;
		}
	}
	void print()
	{
		for (int i = 0; i < top+1; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	Stack s;
	s.push(5);
	s.push(10);
	s.push(15);
	s.push(20);
	s.print();
	return 0;
}
