#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void Selection_Sort(int a[], int length)
{
	for (int i = 0; i < (length-1); i++)
	{
		int min = i;
		for (int j = i+1; j < length; j++)
		{
			if(a[j] < a[min])
			{
				min = j;
			}
		}
		if (min!=i)
		{
			swap(a[i], a[min]);
		}
	}
}

int main()
{
	int arr[6] = { 6,5,3,2,1,4 };
	Selection_Sort(arr, 6);
		for (int i = 0; i < 6; i++)
		{
			cout << arr[i] << " " << endl;
		}
}
