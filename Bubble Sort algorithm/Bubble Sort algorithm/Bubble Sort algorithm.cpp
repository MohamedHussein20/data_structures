#include <iostream>
#include <algorithm>
using namespace std;

void Bubble_Sort(int arr[], int n)
{
    bool flag = true;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = false;
            }
            c++;
        }
        if (flag)
        {
            break;
        }
    }
    cout << "# of rounds : " << c << endl;
}

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = { 100,60,20,50,30,90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Bubble_Sort(arr, n);
    PrintArray(arr, n);
}
