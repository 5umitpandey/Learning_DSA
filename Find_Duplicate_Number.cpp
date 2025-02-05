//https://leetcode.com/problems/find-the-duplicate-number/

    //Approach 1 (Sorting and Checking Pairs)
    // int findDuplicate(vector<int>& nums) 
    // {
    //     sort(nums.begin(), nums.end());

    //     for( int i=1; i < nums.size(); i++ )
    //     {
    //         if( nums[i-1] == nums[i])
    //         {
    //             return nums[i];
    //         }
    //     }
    //     return -1;
    // }
    // O(n log n)
    // O(1)


    //Approach 2 (Hashing | Freq Array )
    // int findDuplicate(vector<int>& nums)
    // {
    //     vector <int> freq(nums.size(), 0);

    //     for(int num : nums)
    //     {
    //         freq[num]++;

    //         if( freq[num] > 1 )
    //         {
    //             return num;
    //         }
    //     }
    //     return -1;
    // }
    // O(n)
    // O(n)

    //Approach 3 (Tortoise & Hare Algorithm | Cycle Detection)
    int findDuplicate(vector<int>& nums)
    {
        int slow = nums[0];
        int fast = nums[0];
        
        do
        {
            slow = nums[ slow ];
            fast = nums[ nums[fast] ];
        } while( slow != fast );

        fast = nums[0];
        while( slow != fast )
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
    // O(n)
    // O(n)
