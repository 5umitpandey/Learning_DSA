/*
Quick Sort

Divide on the basis of pivot element & Conquer (compare and combine)
Pivot Selection (random, first, last, mid, median of 3(first, last, mid))
Partitioning: rearranging of array on the basis of value greater (move right part) or smaller(move left)
Recursive Sorting: keeps on putting pivot in its actual position

Best Case: 
Avg Case: 
Worst Case: 
*/

//Pivod as Mid element
//Partition as Hoare's

#include <iostream>
using namespace std;

int Partition(int arr[], int L, int H)
{
    int Piv = arr[L + (H-L) / 2];
    int i = L - 1;
    int j = H + 1;

    while(true)
    {
        do
            i++;
        while( arr[i] < Piv );

        do
            j--;
        while( arr[j] > Piv );

        if( i>= j )
            return j;
        
        swap(arr[i], arr[j]);
    }
}

void QuickSort(int arr[], int L, int H)
{
    if( L < H )
    {
        int Piv = Partition(arr, L, H);
        
        QuickSort(arr, L, Piv);
        QuickSort(arr, Piv + 1, H);
    }
}

void PrintArray(int arr[], int n)
{
    for( int i=0; i<n; i++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {900, 500, 44, -12, 88, -77, 215};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nArray is "; PrintArray(arr, n);

    QuickSort(arr, 0, n-1);

    cout << "\nSorted Array: "; PrintArray(arr, n);

    return 0;
}