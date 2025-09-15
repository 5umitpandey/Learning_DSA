//https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

//Approach 1 | Bruteforce

vector<int> leaders(vector<int>& arr) 
    {   
        vector <int> res;
        for( int i=0; i<arr.size(); i++ )
        {   
            bool leader = true;
            for( int j=i+1; j<arr.size(); j++ )
            {
                if( arr[j] > arr[i] )
                {
                    leader = false;
                    break;
                }
            }
            
            if( leader )
            {
                res.push_back( arr[i] );
            }
        }
        
        return res;
    }


//Approach 2 | Reverse traversing by updating max element
    vector<int> leaders(vector<int>& arr) 
    {
        if ( is_sorted(arr.begin(), arr.end(), greater<int>()) )
        {
            return arr;
        }
        
        vector <int> res;
	    int leader = arr[arr.size()-1];
	    res.push_back(leader);
        for( int i=arr.size()-2; i>=0; i-- )
        {
            if( leader <= arr[i] )
            {
                leader = arr[i];
                res.push_back(leader);
            }
        }
        
        reverse( res.begin(), res.end() );
        return res;
    }
