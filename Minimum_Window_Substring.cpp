//https://leetcode.com/problems/minimum-window-substring/description/

string minWindow(string s, string t) 
    {
        int minLength = INT_MAX; // To store the length of the minimum window
        string result = "";      // To store the final result

        // Loop through all possible substrings of s
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                string window = s.substr(i, j - i + 1);

                // Check if this substring contains all characters of t
                unordered_map<char, int> freq;
                for (char c : t) freq[c]++;

                for (char c : window) {
                    if (freq.find(c) != freq.end()) {
                        freq[c]--;
                        if (freq[c] == 0) freq.erase(c);
                    }
                }

                // If all characters of t are present
                if (freq.empty() && window.size() < minLength) {
                    minLength = window.size();
                    result = window;
                }
            }
        }

        return result;
    }
