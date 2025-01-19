//https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/max-circular-subarray-sum-1587115620

int circularSubarraySum(vector<int> &arr) 
    {
        int n = arr.size();

        int max_normal = INT_MIN, max_current = 0;
        for (int i = 0; i < n; ++i) {
            max_current = std::max(arr[i], max_current + arr[i]);
            max_normal = std::max(max_normal, max_current);
        }
    
        if (max_normal < 0) {
            return max_normal;
        }
    
        int total_sum = 0;
        for (int i = 0; i < n; ++i) {
            total_sum += arr[i];
        }
    
        int min_normal = INT_MAX, min_current = 0;
        for (int i = 0; i < n; ++i) {
            min_current = std::min(arr[i], min_current + arr[i]);
            min_normal = std::min(min_normal, min_current);
        }
    
        int max_circular = total_sum - min_normal;
    
        return std::max(max_normal, max_circular);
    }
