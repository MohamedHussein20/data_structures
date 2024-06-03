#include <iostream>
#include<algorithm>
using namespace std;
void Merge(int arr[], int l, int m, int r)  //m = l + (r-l) / 2
{
	int i, j, k;
	int n1 = m - l + 1; //First subarray is arr[ l...m]          "4"
	int n2 = r - m;     //Second subarray is arr[ m+1...r]       "3"
	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
	
	for (int j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
	}

	i = j = 0;
	k = l;

	while (i < n1 && j< n2)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}

		else
		{
			arr[k] = R[j];
			j++;
		}

		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void Merge_Sort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		Merge_Sort(arr, l, m);
		Merge_Sort(arr, m + 1, r);
		Merge(arr, l, m, r);
	}
}

void Print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[6] = { 9,10,20,5,60,70 };
	Merge_Sort(arr, 0, 5);
	Print(arr, 6);
}