/*
Bubble Sort
Comparing and Swapping first two elements in each loop

Total passes: n-1
Total comparasions: n*(n-1)/2

Best Case: Ω (n)
Avg Case:  θ (n^2)
Worst Case: O (n^2)
Space: O (1) 
*/

#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;

    for(int i=0; i<n-1; i++)
    {
        swapped = false;

        for(int j=0; j<n-i-1; j++) //only compares elements that haven’t been sorted yet
        {
            if( arr[j] > arr[j+1] )
            {
                swap( arr[j], arr[j+1] );
                swapped = true;
            }
        }

        if( swapped == false )
            break;
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
    int arr[6] = {900, 44, -12, 88, 77, 215};
    char string[12] = "Hello World";

    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(string) / sizeof(string[0]);

    cout << "\nArray: "; PrintArray(arr, n);
    cout << "\nString: "; cout << string;

    BubbleSort(arr, n);
    BubbleSort(string, m);

    cout << "\nSorted Array: "; PrintArray(arr, n);
    cout << "\nSorted String: "; PrintArray(arr, n);
}