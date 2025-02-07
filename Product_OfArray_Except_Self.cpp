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
    //     if (zero_count > 1) 
    //     {
    //         return result; // All elements will be zero
    //     }

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


    //Approach 2 | (Left Right Sum)
    // vector<int> productExceptSelf(vector<int> &nums)
    // {
    //     vector<int> left(nums.size(), 1);
    //     vector<int> right(nums.size(), 1);
    //     vector<int> result(nums.size(), 1);

    //     //Left side filling
    //     for(int i=1; i<nums.size(); i++)
    //     {
    //         left[i] = left[i-1] * nums[i-1];
    //     }

    //     //Right
    //     for(int i=nums.size()-2; i>=0; i--)
    //     {
    //         right[i] = right[i+1] * nums[i+1];
    //     }

    //     //Result
    //     for(int i=0; i<nums.size(); i++)
    //     {
    //         result[i] = left[i] * right[i];
    //     }

    //     return result;
    // }
    //O(n)
    //O(n)

    //Boundary Cases:
    //OP[0]   = Right[1]
    //OP[n-1] = Left[n-2]

    //https://www.youtube.com/watch?v=gREVHiZjXeQ
    //Approach 3 | Implace O(1) Space
    vector<int> productExceptSelf(vector<int> &nums) 
    {
        int n = nums.size();
        vector<int> output;
        if(n<1)
            return output;
        
        //LHS multiplication
        int product = 1;
        for(int i=0;i<n;++i)
        {
            product *= nums[i];
            output.push_back(product);            
        }
        
        //Traverse from right and update output array
        product = 1;    //stores multiplication of RHS 
        for(int i=n-1;i>0;--i)
        {
            output[i] = output[i-1]*product;
            product *= nums[i];
        }
        output[0] = product;    //Boundary Case
        
        return output;
    }
    //O(n)
    //O(1)
