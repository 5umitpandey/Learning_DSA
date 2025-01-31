/*
Given Start and Departure time of Trains. Find the minimum no. of trains so that no train has to wait.
Two Pointer Approach
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Min_Platforms(vector<int> arr, vector<int> dep) 
{
    int n = arr.size();

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int plat_needed = 1, result = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        // If next event in sorted order is arrival, increment count of platforms needed
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        }
        // Else decrement count of platforms needed
        else {
            plat_needed--;
            j++;
        }

        // Update result if needed
        if (plat_needed > result) {
            result = plat_needed;
        }
    }

    return result;
}


int main()
{
    vector <int> arr = {900, 940,  950,  1100, 1500, 1800};
    vector <int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    cout << Min_Platforms( arr, dep );

    return 0;
}