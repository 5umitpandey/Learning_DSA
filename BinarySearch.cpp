/*
Binary search

Data SHOULD be sorted.
Find MID
Divide and compare continously

Iterative and Recursive Techniques

function returns the location of the target number
*/
#include <bits/stdc++.h>
using namespace std;

int Iterative_BinarySearch(int arr[], int low, int high, int k )
{
    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] == k)
            return mid;

        if(arr[mid] < k)
            low = mid + 1;
        
        else
            high = mid - 1;
    }
    return -1;
}

int Recursive_BinarySearch(int arr[], int low, int high, int x )
{
    if(high >= low)
    {
        int mid = low + (high - low) / 2;

        if( arr[mid] == x )
            return mid;

        if( arr[mid] > x )
            return Recursive_BinarySearch(arr, low, mid-1, x);
        
        return Recursive_BinarySearch(arr, mid+1, high, x);
    }

    return -1;
}

//Print Array
void PrintArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    //Sorted Array
    int arr[6] = {-77, -12, 44, 88, 215, 900};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array is: "; PrintArray(arr, n);

    int k = 215;
    cout << "\nLocation of " << k << " is at: " << Iterative_BinarySearch(arr, 0, n-1, k) + 1;
    cout << endl;
    
    k = 1;

    if( Recursive_BinarySearch(arr, 0, n-1, k) == -1 )
        cout << "Location of " << k << " IS NOT FOUND";
    else
        cout << "Location of " << k << " is at " << Recursive_BinarySearch(arr, 0, n-1, k);

    k = 900;

    if( Recursive_BinarySearch(arr, 0, n-1, k) == -1 )
        cout << "Element NOT FOUND";
    else
        cout << "\nLocation of " << k << " is at " << Recursive_BinarySearch(arr, 0, n-1, k) + 1;

}