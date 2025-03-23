//https://leetcode.com/problems/minimum-window-substring/description/

// string minWindow(string s, string t) 
    // {
    //     int minLength = INT_MAX; // To store the length of the minimum window
    //     string result = "";      // To store the final result

    //     // Loop through all possible substrings of s
    //     for (int i = 0; i < s.size(); i++) {
    //         for (int j = i; j < s.size(); j++) {
    //             string window = s.substr(i, j - i + 1);

    //             // Check if this substring contains all characters of t
    //             unordered_map<char, int> freq;
    //             for (char c : t) freq[c]++;

    //             for (char c : window) {
    //                 if (freq.find(c) != freq.end()) {
    //                     freq[c]--;
    //                     if (freq[c] == 0) freq.erase(c);
    //                 }
    //             }

    //             // If all characters of t are present
    //             if (freq.empty() && window.size() < minLength) {
    //                 minLength = window.size();
    //                 result = window;
    //             }
    //         }
    //     }

    //     return result;
    // }
    //O(n^3)
    //O(m)

    string minWindow(string s, string t) 
    {
        if (t.empty() || s.empty()) return "";

        unordered_map<char, int> charCount;
        for (char c : t) charCount[c]++;

        int required = charCount.size();
        int formed = 0;

        unordered_map<char, int> windowCount;
        int left = 0, right = 0;
        int minLength = INT_MAX, minLeft = 0;

        while (right < s.length()) {
            char c = s[right];
            windowCount[c]++;

            if (charCount.count(c) && windowCount[c] == charCount[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                c = s[left];

                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minLeft = left;
                }

                windowCount[c]--;
                if (charCount.count(c) && windowCount[c] < charCount[c]) {
                    formed--;
                }
                left++;
            }

            right++;
        }

        return minLength == INT_MAX ? "" : s.substr(minLeft, minLength);
    }
    //O(n)
    //O(m)
