/*
Selection Sort
Choose first element as largest/smallest
put it in the first/last position
in each loop
*/

#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int minn = i;

        //cout << "i is " << i << " min is " << minn;

        for(int j=i+1; j<n; j++)
        {   
            //cout << " j is " << j;
            if( arr[j] < arr[minn] )
            {   
                //cout << " arr[j] is " << arr[j] << " arr[min] " << arr[minn];
                minn = j;
            }

            //cout << endl;
        }

        //cout << " arr[i] is " << arr[i];

        if( minn != i )
            swap( arr[minn], arr[i] );

        //cout << " after swapping " << " arr[minn] " << arr[minn] << " arr[i]" << arr[i] << endl;
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

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nArray is: "; PrintArray(arr, n); cout << endl;

    SelectionSort(arr, n);

    cout << "\nSorted Array: "; PrintArray(arr, n);

    return 0;
}
