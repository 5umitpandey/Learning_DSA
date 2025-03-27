//https://leetcode.com/problems/trapping-rain-water/description/

//Approach 1 | BruteForce
    int trap(vector<int>& height) 
    {
        int n = height.size();
        if (n == 0) return 0; // Edge case for empty elevation map
    
        int totalWater = 0;
    
        for (int i = 0; i < n; i++) {
            // Find the max height to the left of the current bar
            int maxLeft = 0;
            for (int j = 0; j <= i; j++) {
                maxLeft = max(maxLeft, height[j]);
            }
    
            // Find the max height to the right of the current bar
            int maxRight = 0;
            for (int j = i; j < n; j++) {
                maxRight = max(maxRight, height[j]);
            }
    
            // Calculate water trapped at the current bar
            totalWater += min(maxLeft, maxRight) - height[i];
        }
    
        return totalWater;    
    }
//O(n^2)
//O(1)
