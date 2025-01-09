#include <bits/stdc++.h>
using namespace std;
/*
Pairs
Vector
List
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
    vector<int>::reverse_iterator it_rb = v.rbegin(); //Reverse iterator means + to left side

    //Printing
    cout << v[0] << " " << v.at(0);
    cout << v.back() << " "; //last element

    for( vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    for( auto it = v.begin(); it != v.end(); it++ )
    {
        cout << *it << " ";
    }

    for( auto it : v )
    {
        cout << it << " ";
    }

    //Deletion
    v.erase( v.begin() + 1); //Delete at index 1

    v.erase( v.begin() + 2, v.begin() + 4); //Delets from index 2 to 4 means 2 and 3 only
    

    //Insertion
    vector<int> v(2, 100); // {100, 100}
    v.insert( v.begin(), 300); // {300, 100, 100}
    v.insert( v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

    vector <int> v_copy(2, 50);
    v.insert( v.begin(), v_copy.begin(), v_copy.end()); // {50, 50, 300, 10, 10, 100, 100}

    //No of elements
    cout << v.size(); //5

    //Pop back: Deletes last element
    v.pop_back();

    //Swap
    v1.swap(v2);

    //Erases entire vector
    v.clear();

    cout << v.empty();
}

//List
void Lists()
{

}

int main()
{
    //Pairs();
    //Vectors();
    //Lists();
    
    return 0;
}
