//https://leetcode.com/problems/longest-common-prefix/description/

string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (size_t i = 0; i < prefix.size(); ++i) 
        {
            // Compare the character at position i with each string in the array
            for (size_t j = 1; j < strs.size(); ++j) 
            {
                // If the current string is shorter than the current prefix length, or the characters don't match
                if (i >= strs[j].size() || strs[j][i] != prefix[i]) 
                {
                    // Shorten the prefix to the current length i
                    return prefix.substr(0, i);
                }
            }
        }

        return prefix;
    }
//O(N∗M)
//O(1)
