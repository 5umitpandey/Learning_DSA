#include <bits/stdc++.h>
using namespace std;
/*
Pairs
Vector
*/


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

//Vector
void Vectors()
{
    vector<int> v;

    v.push_back(1);     //{1}
    v.emplace_back(2);  //{1, 2}

    //Vector Pair
    vector< pair<int, int> > vec;

    vec.push_back({1, 2});  // { {1, 2} }
    vec.emplace_back(3, 4);  // { {1,2}, {3,4} }

    //Declare vector with 5 instances of '20'
    vector<int> v1(5, 20);

    //Declare vector with 5 instances of 'random values'
    vector<int> v2(5);

    //Copy v1 into v3
    vector<int> v3(v1);


    vector<int>::iterator it = v.begin();

    cout << *(it); //Prints 1

    vector<int>::iterator it_e = v.end();
    vector<int>::reverse_iterator it_re = v.rend();
    vector<int>::reverse_iterator it_rb = v.rbegin();

}


int main()
{
    //Pairs();
    Vectors();
    return 0;
}
