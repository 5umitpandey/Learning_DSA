bool check(vector<int>& arr1, vector<int>& arr2) 
{
        if( arr1.size() != arr2.size() )
            return false;
        
        map <int,int> mp1;
        for(int i = 0; i<arr1.size(); i++)
        {
            mp1[arr1[i]]++;
            mp1[arr2[i]]--;
        }
        for(auto x : mp1)
        {
            if(x.second != 0)
               return false;
        }
        return true;
  }
