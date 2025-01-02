#include <bits/stdc++.h>

using namespace std;


// Pairs
void Pairs()
{
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second;

    cout << endl;

    //Nested Pair
    pair<int, pair<int, int>> n_p = {1, {3, 4}};
    cout << p.first << " " << n_p.second.first << " " << n_p.second.second;

    cout << endl;
    
    //Arr Pair
    pair<int, int> arr[] = { {1, 2}, {2, 5}, {5, 1} };
    cout << arr[1].second;
}


int main()
{
    Pairs();

    return 0;
}