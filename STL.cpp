#include <bits/stdc++.h>
using namespace std;
/*
Pairs
Vector
Lists
Deques
Stacks
Queues
Priority Queues
Sets
Multiset
Unordered Set
Map
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
    vector<int> v_(2, 100); // {100, 100}
    v.insert( v_.begin(), 300); // {300, 100, 100}
    v.insert( v_.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

    vector <int> v_copy(2, 50);
    v.insert( v_.begin(), v_copy.begin(), v_copy.end()); // {50, 50, 300, 10, 10, 100, 100}

    //No of elements
    cout << v_.size(); //5

    //Pop back: Deletes last element
    v_.pop_back();

    //Swap
    v1.swap(v2);

    //Erases entire vector
    v_.clear();

    cout << v_.empty();
}

//List
void Lists()
{
    list <int> ls;
    ls.push_back(2);    // {2}
    ls.emplace_back(4); // {2, 4}

    ls.push_front(5);    // {5, 2, 4}
    ls.emplace_front(6); // {6 , 5, 2, 4}

    for( auto it : ls )
    {
        cout << it << " ";
    }

    //Rest is smiliar to vector
}

//Deque
void Deques()
{
    deque <int> dq;
    dq.push_back(1);     // {1}
    dq.push_front(2);    // {2, 1}
    dq.emplace_back(3);  // {2, 1, 3}
    dq.emplace_front(4); // {4, 2, 1, 3}

    dq.pop_back();       // {4, 2, 1}
    dq.pop_front();      // {2, 1}

    for( auto it : dq )
    {
        cout << it << " ";
    }

    cout << dq.front();
}

//Stack
void Stacks()
{   
    //LIFO
    stack <int> st;

    st.push(1);     // {1}
    st.push(3);     // {1, 3}
    st.push(8);     // {1, 3, 8}
    st.emplace(4);  // {1, 3, 8, 4}

    cout << st.top() << " ";   //4
    st.pop();           //Removes 8
    cout << st.size() << " ";  //3
    cout << st.empty() << " "; //0

    stack <int> st1, st2;
    st1.swap(st2);
}

//Queue
void Queues()
{   
    //FIFO
    queue <int> q;
    q.push(1);     // {1}
    q.push(3);     // {1, 3}
    q.emplace(8);  // {1, 3, 8}

    q.back() += 5; // 8+5
    cout << q.back() << " ";  //13
    cout << q.front() << " "; //1

    q.pop();    //Removes 1
    cout << q.front() << " "; //3

    //Swap as same as Stack
}

//P_Queues
void P_Queues()
{
    //MAX Heap
    priority_queue <int> pq;
    
    pq.push(5);     // {5}
    pq.push(3);     // {5, 3}
    pq.push(8);     // {8, 5, 3}
    pq.emplace(10); // {10, 8, 5, 3}

    cout << pq.top() << "\n"; //10
    pq.pop();                 //Removes 10

    
    //MIN Heap
    priority_queue <int, vector<int>, greater<int>> pq1;

    pq1.push(5);     // {5}
    pq1.push(3);     // {3, 5}
    pq1.push(8);     // {3, 5, 8}
    pq1.emplace(10); // {3, 5, 8, 10}

    cout << pq1.top() << "\n"; //3
    pq1.pop();                 //Removes 3
}

//Set
void Sets()
{
    //Sorted Manner
    //Unique Elements only

    set <int> se;
    se.insert(5);     // {5}
    se.insert(3);     // {3, 5}
    se.insert(8);     // {3, 5, 8}
    se.insert(10);    // {3, 5, 8, 10}
    se.emplace(5);    // {3, 5, 8, 10}
    se.insert(3);     // {3, 5, 8, 10}
    se.insert(11);     // {3, 5, 8, 10, 11}
    se.insert(50);     // {3, 5, 8, 10, 11, 50}

    auto it1 = se.find(3); // 0
    auto it2 = se.find(6); // st.end() 

    se.erase(5);    // Removes 5  // {3, 8, 10, 11, 50}

    auto it3 = se.find(8);
    auto it4 = se.find(50);
    se.erase( it1, it2 );   //Deletes from 8 to 50 // {3, 10, 11}
    
    int cnt1 = se.count(1); //0
    int cnt2 = se.count(3); //1

    auto it5 = se.lower_bound(2);
    auto it6 = se.upper_bound(3);
}   

//MultiSet
void MultiSets()
{
    //Stores Duplicates as well unlike set

    multiset <int> ms;
    ms.insert(5);     // {5}
    ms.insert(3);     // {3, 5}
    ms.insert(3);     // {3, 5, 3}
    ms.insert(3);     // {3, 5, 3, 3}
    ms.insert(8);     // {3, 5, 3, 3, 8}
    ms.insert(8);     // {3, 5, 3, 3, 8, 8}

    ms.erase(1);      // Removes ALL 3  // {5, 8, 8}

    cout << ms.count(8) << endl; //2

    ms.erase( ms.find(8) ); //Removes ONE 8 only  // {5, 8}

    //Rest same like Sets()
}

//Unordered_Set
void UnorderedSets()
{
    //Unique but Random Order | O(1)
    unordered_set <int> us;
    us.insert(5);     // {5}
}

//Map
void Maps()
{
    //Key Value Pair
    //Unique Keys & Sorted

    map <int, int> m;
    map <int, pair<int, int> > m1;
    map <pair<int, int>, int > m2;

    m[1] = 2;
    m.emplace( 3,1 );
    m.insert( {2, 4} );

    m2[ {2, 3} ] = 10;

    for( auto it : m )
    {
        cout << it.first << " " << it.second << endl;
    }

    cout << m[5] << endl; //Prints 0 if key not found 

    auto it = m.find(2);
    cout << (*it).second << endl;   //Find Value at given Key


}

int main()
{
    //Pairs();
    //Vectors();
    //Lists();
    //Deques();
    //Stacks();
    //Queues();
    //P_Queues();
    //Sets();
    //MultiSets();
    //UnorderedSets();
    //Maps();
    
    return 0;
}
