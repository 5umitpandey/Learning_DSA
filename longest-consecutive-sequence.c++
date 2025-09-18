//https://leetcode.com/problems/longest-consecutive-sequence/

//Bruteforce
int longestConsecutive(vector<int>& nums) 
    {   
        if( nums.size() == 0 )
            return 0;

        sort(nums.begin(), nums.end());

        set <int> s(nums.begin(), nums.end());

        int count = 1;
        int max_count = 1;

        if (!s.empty()) 
        {
            auto prev = s.begin();         // first element
            auto it = next(s.begin());     // second element
    
            for (; it != s.end(); ++it, ++prev) 
            {
                if (*it == *prev + 1) 
                {
                    count++;
                    max_count = max(max_count, count);
                }
                else 
                {
                    count = 1;
                }
            }
        }

        return max_count;
    }
