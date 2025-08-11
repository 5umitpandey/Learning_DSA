#include <bits/stdc++.h>
using namespace std;

int main()
{   
    //Int
    vector <int> arr = {1, 3, 2, 1, 3};

    //Pre compute
    vector <int> hash(10);

    for(int i=0; i<arr.size(); i++)
    {
        hash[arr[i]] ++;
    }

    // for(int i=0; i<arr.size(); i++)
    // {
    //     cout << hash[i] << " ";
    // }

    //cout << hash[3];

    //String
    string s = "ababababc";
    vector <int> hashh(26);

    for(int i=0; i<s.size(); i++)
    {
        hashh[s[i] - 'a' ] ++;
    }

    // for(int i=0; i<s.size(); i++)
    // {
    //     if( hashh[i] > 0 )
    //         cout << hashh[i] << " ";
    // }

    //cout << hashh[ 'a' - 'a' ];


    //Map: Less Memory
    //INT
    vector <int> arrr = {1, 3, 22, 1, 13, 22};

    map <int, int> mpp;
    for(int i=0; i<arrr.size(); i++)
    {
        mpp[ arrr[i] ]++;
    }

    //Iterating through map:
    // for( auto it : mpp )
    // {
    //     cout << it.first << " " << it.second << endl;
    // }

    //cout << mpp[22];


    //String
    map <char, int> m;
    for(int i=0; i<s.size(); i++)
    {
        m[ s[i] ]++;
    }

    //cout << m['A'];




    return 0;
}