//https://www.codechef.com/problems/MYSITM
/*
Binary Search
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool can_fit_in_square(int n, int h, int w, int s) 
{
    return (s / h) * (s / w) >= n;
}

int minimum_square_side(int n, int h, int w) 
{
    int low = max(h, w);
    int high = max(h, w) * n;
    while (low < high) 
    {
        int mid = (low + high) / 2;
        if (can_fit_in_square(n, h, w, mid)) 
        {
            high = mid;
        }
        else 
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n = 10, h = 2, w = 3;

    cout << minimum_square_side(n, h, w);

    return 0;
}