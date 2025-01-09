//https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/next-permutation5226

void nextPermutation(vector<int>& arr) 
    {
        // code here
        int temp = -1
        ;
        for(int i=arr.size() - 1; i>=1; i--)
        {
            if( arr[i] > arr[i-1] )
            {
                temp = i - 1;
                break;
            }
        }
        
        if( temp == -1 )
        {
            sort( arr.begin(), arr.end() );
            return;
        }
        
        int small = temp + 1;
        for(int i = arr.size() - 1; i>temp; i--)
        {
            if( arr[i] > arr[temp] )
            {
                swap( arr[i], arr[temp] );
                break;
            }
        }
        
        // swap( arr[temp], arr[small] );
        
        sort( arr.begin() + temp + 1, arr.end() );
    }
