//https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/kadanes-algorithm-1587115620

int maxSubarraySum(vector<int> &arr) 
{
        int sum = arr[0], MaxEnd = arr[0];
        
        for(int i=1; i<arr.size(); i++)
        {
            MaxEnd = max( MaxEnd + arr[i], arr[i]);
            sum = max( sum, MaxEnd );
        }
        
        return sum;
}
