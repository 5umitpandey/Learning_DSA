/*
Merge Sort

Divide, Conquer & Merge
Divide array in half till we get two elements
Compare and swap those two elements
merge the swapped elements back in the array

Best Case: Ω (N Log (N))
Avg Case:  θ (N Log (N))
Worst Case: O (N Log (N))
Space: O (N)
*/

#include <iostream>
using namespace std;

//Merge 2 Arrays Function
void Merge(int arr[], int L, int M, int R)
{
    int Sub_A_1 = M - L + 1;
    int Sub_A_2 = R - M;

    int Left_A[Sub_A_1]; int Right_A[Sub_A_2];

    for( int i=0; i<Sub_A_1; i++ )
        Left_A[i] = arr[L + i];
    
    for( int j=0; j<Sub_A_2; j++ )
        Right_A[j] = arr[M + 1 + j];

    //Merging temp arr back in arr[]
    int I_A1 = 0; int I_A2 = 0; int I_M_A = L;

    while( (I_A1 < Sub_A_1) && (I_A2 < Sub_A_2) )
    {
        if( Left_A[I_A1] <= Right_A[I_A2] )
        {
            arr[I_M_A] = Left_A[I_A1];
            I_A1++;
        }
        else
        {
            arr[I_M_A] = Right_A[I_A2];
            I_A2++;
        }
        I_M_A++;
    }

    while( I_A1 < Sub_A_1 )
    {
        arr[I_M_A] = Left_A[I_A1];
        I_A1++;
        I_M_A++;
    }

    while( I_A2 < Sub_A_2 )
    {
        arr[I_M_A] = Right_A[I_A2];
        I_A2++;
        I_M_A++;
    }
}

//Merge Sort Function
void MergeSort(int arr[], int L, int R)
{
    if( L >= R )
        return;
    
    int M = L + (R - L) / 2;

    MergeSort(arr, L, M);
    MergeSort(arr, M+1, R);
    
    Merge(arr, L, M, R);
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
    int arr[] = {900, 44, -12, 88, -77, 215};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nArray is "; PrintArray(arr, n);

    MergeSort(arr, 0, n-1);

    cout << "\nSorted Array: "; PrintArray(arr, n);

    return 0;
}