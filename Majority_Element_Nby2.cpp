//https://leetcode.com/problems/majority-element/

 //Approach 1 | BruteForce
    // int majorityElement(vector<int>& nums) 
    // {
    //     int n = nums.size();
    //     for (int i = 0; i < n; i++) 
    //     {
    //         int count = 0;
    //         for (int j = 0; j < n; j++) 
    //         {
    //             if (nums[j] == nums[i]) 
    //             {
    //                 count++;
    //             }
    //         }
    //         if (count > n / 2) 
    //         {
    //             return nums[i];
    //         }
    //     }
    //     return -1;
    // }
    //O(n^n)
    //O(1)


    //Approach 2 | Hashmap
    // int majorityElement(vector<int>& nums) 
    // {
    //     unordered_map<int, int> counts;
    //     int n = nums.size();
    //     for (int num : nums) 
    //     {
    //         counts[num]++;
    //         if (counts[num] > n / 2) 
    //         {
    //             return num;
    //         }
    //     }
    //     return -1;
    // }
    //O(n)
    //O(n)


    //Approach 3 | Boyer-Moore Voting Algorithm
    int majorityElement(vector<int>& nums) 
    {
        int candidate = 0;
        int count = 0;
        for (int num : nums) 
        {
            if (count == 0) 
            {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
    //O(n)
    //O(1)
