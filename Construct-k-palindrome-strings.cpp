//https://leetcode.com/problems/construct-k-palindrome-strings/?envType=daily-question&envId=2025-01-11

bool canConstruct(string s, int k) 
    {
        if( s.size() < k ) return false;
        
        unordered_map<char, int> count;
        for (char c : s) count[c]++;

        int oddCount = 0;
        for( auto &entry : count )
        {
            if( entry.second % 2 != 0)
            {
                oddCount++;
            }
        }

        return oddCount <= k;
    }
