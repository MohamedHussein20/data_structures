#include <iostream>
#include <algorithm>
using namespace std;
int Binary_Search(int arr[], int l, int h, int element)
{
	while (l <= h)
	{
		int m = (l + h) / 2;
		if (arr[m]==element)
		{
			return m;
		}
		else if (arr[m] > element)
		{
			h = m - 1;
		}
		else if (arr[m] < element)
		{
			l = m + 1;
		}
	}
	return -1;
}
int main()
{
	int arr[] = { 2,3,4,10,40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int num;
	cout << "Enter an integer" << endl;
	cin >> num;


	int result = Binary_Search(arr, 0, n - 1, num);


	if (result == -1)
	{
		cout << "The Number : " << num << " Was not found." << endl;
	}
	else
	{
		cout << "The Number : " << arr[result] << " Was found at the index : " << result << endl;
	}
	return 0;
}