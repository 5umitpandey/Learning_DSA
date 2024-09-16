/*
Array

Array Creation      : O(n)
Find Element        : O(n)
Insert Element      : O(n)
Remove Element      : O(n)
Reverse Array       : O(n)
Remove Duplicates   : O(n logn)
Alternate Swapping  : O(n)    
*/

#include <iostream>
using namespace std;

// Print Array
void PrintArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Find Element Function
int findElement(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;

    return -1;
}

//Insert Function
void insertElement(int arr[], int &n, int x, int pos) {
    // Ensure the position is within the bounds
    if (pos < 0 || pos > n) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Shift elements to the right
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[pos] = x;

    // Increase the size of the array
    n++;
}

//Delete Function
void DeleteElement(int arr[], int &n, int key)
{
    int pos = findElement(arr, n, key);

    if (pos == -1) {
        cout << "Element not found";
        return;
    }

    // Deleting element
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;
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

// Remove Duplicates
int RemoveDuplicates(int arr[], int n)
{
    if (n == 0 || n == 1)
        return n;

    int j = 0; // To store index of next unique element

    for (int i = 0; i < n; i++)
    {
        bool isDuplicate = false;
        for (int k = 0; k < j; k++)
        {
            if (arr[i] == arr[k])
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)
        {
            arr[j++] = arr[i];
        }
    }

    return j;
}

//Alternate Swapping
// 1 3 5 9 6 8   ->     3 1 9 5 8 6
int Alt_Swap(int arr[], int n)
{
    for(int i=0; i<n-1; i += 2)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
} 

int main() 
{
    //Array Creation
    int arr[11] = {11, -88, 56, 15, 32, -5, 4, -64, 7, 7, 4};    
    int n = 11;

    cout << "Array is: ";
    PrintArray(arr, n);
    
    int x, pos;

    //For inserting
    // x = 10, pos = 6;
    // cout << "\nAfter Inserting " << x << " at position " << pos << ": ";
    // insertElement(arr, n, x, pos);
    // PrintArray(arr, n);

    //For deleting
    // x = 11;
    // DeleteElement(arr, n, x);
    // cout << "\nAfter Deleting " << x << " from array: ";
    // PrintArray(arr, n);

    //Reverse Array
    // cout << "\nAfter Reversing: ";
    // ReverseArray(arr, 0, n-1);
    // PrintArray(arr, n);

    //Remove Duplicate
    // cout << "\nAfter removing duplicate: ";
    // RemoveDuplicates(arr, n);
    // PrintArray(arr, n);

    //Alternate elements swapping
    // cout << "\nAfter Swapping Alternate elements: ";
    // Alt_Swap(arr, n);
    // PrintArray(arr, n);

    cout << "\n1. Insertion\n2. Deletion\n3. Reverse Array\n4. Remove Duplicates\n5. Alternate Elements Swapping\n";

    int input; cout << "Enter an option: "; cin >> input;
    switch (input)
    {
        case 1:
            cout << "Enter element to insert: "; cin >> x; cout << "Enter position: "; cin >> pos;
            insertElement(arr, n, x, pos-1);
            cout << "\nAfter Inserting " << x << " at position " << pos << "\nArray is: "; PrintArray(arr, n);
            break;
        case 2:
            cout << "Enter element to delete: "; cin >> x;
            DeleteElement(arr, n, x);
            cout << "\nAfter Deleting " << x << " from array\nArray is: "; PrintArray(arr, n);
            break;
        case 3:
            cout << "Reversing the array";
            ReverseArray(arr, 0, n-1);
            n = sizeof(arr) / sizeof(arr[0]);
            cout << "\nAfter Reversing: "; PrintArray(arr, n);
            break;
        case 4:
            cout << "Removing Duplicates";
            n = RemoveDuplicates(arr, n);
            cout << "\nAfter removing duplicates: "; PrintArray(arr, n);
            break;
        case 5:
            cout << "Swapping Alternate Elements";
            Alt_Swap(arr, n);
            cout << "\nAfter Swapping Alternate elements: "; PrintArray(arr, n);
            break;
        default:
            cout << "Invalid response!";
            exit(0);
    }
}
