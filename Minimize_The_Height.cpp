//https://www.geeksforgeeks.org/problems/minimize-the-heights-i/1

int getMinDiff(int k, vector<int> &arr) 
    {
        // code here
        int n = arr.size();
        if (n == 1) return 0;
        
        sort(arr.begin(), arr.end());
    
        int result = arr[n-1] - arr[0];
    
        int smallest = arr[0] + k;
        int largest = arr[n-1] - k;
    
        for (int i = 0; i < n - 1; ++i) 
        {
            int minElement = min(smallest, arr[i+1] - k);
            int maxElement = max(largest, arr[i] + k);
            
            result = min(result, maxElement - minElement);
        }
    
        return result;  
    }
