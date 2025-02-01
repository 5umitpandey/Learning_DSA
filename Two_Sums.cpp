//https://leetcode.com/problems/two-sum/

//2nd Approach
vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map <int, int> NMap;
        for(int i=0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if( NMap.find(complement) != NMap.end() )
            {
                return {NMap[complement], i};
            }
            NMap[nums[i]] = i;
        }
        
        return {};
    }
//O(n)



//3rd Approach
vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map <int, int> NMap;

        for(int i=0; i < nums.size(); i++)
        {
            int c = target - nums[i];
            if( NMap.count(c) )
            {
                return {NMap[c], i};
            }
            NMap[ nums[i] ] = i;
        }    
        return {};
    }
//O(nlogn)
