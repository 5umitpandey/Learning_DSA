/*
Linear search
Simple iteration from 0 to n
untill we found the desired target number

function returns the location of the target number

Best Case: Ω (1)
Avg Case:  θ (n)
Worst Case: O (n)
Space: O (1)
*/

int LinearSearch(int arr[], int n, int k )
{
    for(int i=0; i<n; i++)
    {
        if( arr[i] == k)
            return i+1;
    }

    return -1;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {44, 88, -12, 90, -77};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = -12;
    cout << "Location is: " << LinearSearch(arr, n, k);
}