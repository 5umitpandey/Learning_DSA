//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/1537174432/

//Approach 1 | Brute Force
    // int lengthOfLongestSubstring(string s) 
    // {
    //     int n = s.length();
    //     int maxLength = 0;

    //     for (int i = 0; i < n; ++i) 
    //     {
    //         bool charSet[256] = {false};
    //         int currentLength = 0;

    //         for (int j = i; j < n; ++j) 
    //         {
    //             if (charSet[s[j]]) 
    //             {
    //                 break;
    //             }
    //             charSet[s[j]] = true;
    //             ++currentLength;
    //         }
    //         maxLength = max(maxLength, currentLength);
    //     }

    //     return maxLength;
    // }
    //O(n^2)

    
    //Approach 2 | Sliding Window | Vector
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int maxLength = 0;
        vector<int> charIndex(256, -1);

        int left = 0;

        for (int right = 0; right < n; ++right) 
        {
            if (charIndex[s[right]] != -1) 
            {
                left = max(left, charIndex[s[right]] + 1);
            }
            
            charIndex[s[right]] = right;
            
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
    //O(n)
    //O(1)


    //Approach 3 | Sliding Window | Unordered Map
    // int lengthOfLongestSubstring(string s)
    // {
    //     int n = s.length();
    //     int maxLength = 0;
    //     unordered_map<char, int> charIndex;

    //     int left = 0;

    //     for (int right = 0; right < n; ++right) 
    //     { 
    //         if (charIndex.find(s[right]) != charIndex.end()) 
    //         {
    //             left = max(left, charIndex[s[right]] + 1);
    //         }
            
    //         charIndex[s[right]] = right;
            
    //         maxLength = max(maxLength, right - left + 1);
    //     }

    //     return maxLength;
    // }
    //O(n)
    //O(1)
