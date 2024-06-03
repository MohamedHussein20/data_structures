#include <iostream>
#include<stack>
#include<string>
using namespace std; 
bool arePair(char open, char close)
{
	if (open=='(' && close==')')
	{
		return true;
	}

	else if (open == '{' && close == '}')
	{
		return true;
	}

	else if (open == '[' && close == ']')
	{
		return true;
	}
	return false;
}
bool areBalanced(string exp)
{
	stack<char>s;
	for (int i = 0; i < exp.size(); i++)
	{
		if (exp[i]=='(' || exp[i]=='{' || exp[i] == '[')
		{
			s.push(exp[i]);
		}
		else if ((exp[i] == ')' || exp[i] == '}' || exp[i] == ']'))
		{
			if ( s.empty() || arePair( s.top() , exp[i] ) )
			{
				return false;
			}
			else
			{
				s.pop();
			}
		}
		return s.empty();
	}
}
int main()
{
	string s;
	cin >> s;
	if (areBalanced(s))
	{
		cout << "Balanced" << endl;
	}
	else
	{
		cout << "Balanced" << endl;
	}
	return 0;
}