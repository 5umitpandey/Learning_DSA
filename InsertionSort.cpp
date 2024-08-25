/*
Insertion Sort

Compare & Swap first element with the second element
Compare & Swap second element in the second loop (i=2)
at the end of first loop, largest and smallest are in the correct position
*/

#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int key = arr[i];
        int j = i-1;

        while( j >= 0 && arr[j] > key )
        {
            arr[j+1] = arr[j];
            j =  j - 1;
        }
        arr[j+1] = key;
    }
}

void PrintArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[6] = {900, 44, -12, 88, -77, 215};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nArray: "; PrintArray(arr, n);

    InsertionSort(arr, n);

    cout << "\nSorted Array: "; PrintArray(arr, n);
}