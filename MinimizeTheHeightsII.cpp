//https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/minimize-the-heights3351

int getMinDiff(vector<int> &arr, int k) 
    {
        int n = arr.size();
        
        if( n == 1 ) return 0;
        
        sort(arr.begin(), arr.end());
        
        int diff = arr[n-1] - arr[0];
        
        int MinH, MaxH;
        
        for(int i=1; i<n; ++i)
        {
            if( arr[i] < k ) continue;
            
            MinH = min( arr[0] + k, arr[i] - k);
            MaxH = max( arr[i-1] + k, arr[n-1] - k);
            
            diff = min(diff, MaxH - MinH);
        }
        
        return diff;
    }
