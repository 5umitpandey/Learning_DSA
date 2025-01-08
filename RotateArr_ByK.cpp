//https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/rotate-array-by-n-elements-1587115621

void rotateArr(vector<int>& arr, int d) 
    {
        // code here
        int n = arr.size();
    
        d = d % n;
    
        reverse(arr.begin(), arr.begin() + d);
        reverse(arr.begin() + d, arr.end());
        
        reverse(arr.begin(), arr.end());
    }
