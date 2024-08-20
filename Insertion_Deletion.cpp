#include <bits/stdc++.h>
using namespace std;

//Print Array
void PrintArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

//Find Element Function
int findElement(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == key)
            return i;

    return -1;
}

//Insert Function
void insertElement(int arr[], int n, int x, int pos)
{
    for (int i = n - 1; i >= pos; i--)
        arr[i + 1] = arr[i];

    arr[pos] = x;
}

//Delete Function
int DeleteElement(int arr[], int n, int key)
{
    int pos = findElement(arr, n, key);

    if (pos == -1) {
        cout << "Element not found";
        return n;
    }

    // Deleting element
    int i;
    for (i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    return n - 1;
}

//Reverse Array
void ReverseArray(int arr[], int start, int end)
{   
    if(start >= end)
        return;
    
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    //Call Function Recusively
    ReverseArray(arr, start + 1, end - 1);
}

//Remove Duplicate
void RemoveDuplicates(int arr[], int n)
{
    int mark[n] = {1};

    for (int i = 0; i < n; i++) 
    {
        if (mark[i] == 1) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                if (arr[i] == arr[j]) 
                    mark[j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) 
    {
      if (mark[i] == 0)
          cout << arr[i] << " ";
    }
}

int main() 
{
    //Array Creation
    int arr[12] = {11, -88, 56, 15, 32, -5, 4, -64, 7, 7, 4};
    
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Before Insertion: ";
    PrintArray(arr, n);
    
    //For inserting
    int x = 10, pos = 6;

    cout << "\nAfter Inserting " << x << " at position " << pos << ": ";
    
    insertElement(arr, n, x, pos);
    
    n = sizeof(arr) / sizeof(arr[0]);
    PrintArray(arr, n);

    //For deleting
    x = 11;
    
    DeleteElement(arr, n, x);

    n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nAfter Deleting " << x << " from array: ";
    PrintArray(arr, n);

    //Reverse Array
    cout << "\nAfter Reversing: ";
    ReverseArray(arr, 0, n-1);
    PrintArray(arr, n);

    //Remove Duplicate
    cout << "\nAfter removing duplicate: ";
    RemoveDuplicates(arr, n);
    n = sizeof(arr) / sizeof(arr[0]);
    // PrintArray(arr, n);

}