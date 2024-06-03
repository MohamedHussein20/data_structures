#include <iostream>
#include<algorithm>
using namespace std;

void Insertion_Sort(int arr[], int length)
{
    int key, j;
    for (int i = 1; i < length; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
	int arr[] = { 80,90,60,30,50,70,40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Insertion_Sort(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}

}