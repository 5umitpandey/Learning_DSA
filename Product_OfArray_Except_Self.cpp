//https://leetcode.com/problems/product-of-array-except-self/

//Approach 1 (Brute Force | Division)
    // vector<int> productExceptSelf(vector<int>& nums) 
    // {
    //     int n = nums.size();
    //     int nums_product = 1;
    //     int zero_count = 0;
    //     int zero_index = -1;

    //     for (int i = 0; i < n; i++) 
    //     {
    //         if (nums[i] != 0) 
    //         {
    //             nums_product *= nums[i];
    //         }
    //         else 
    //         {
    //             zero_count++;
    //             zero_index = i; // Keep track of the index with zero
    //         }
    //     }

    //     vector<int> result(n, 0);

    //     if (zero_count == 0) 
    //     {
    //         // No zeros, use division
    //         for (int i = 0; i < n; i++) 
    //         {
    //             result[i] = nums_product / nums[i];
    //         }
    //     }
    //     else if (zero_count == 1) 
    //     {
    //         // One zero, set the value at zero_index to the product
    //         result[zero_index] = nums_product;
    //     }
        
    //     return result;
    // }
    //O(n)
    //O(n)


