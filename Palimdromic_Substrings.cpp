//https://leetcode.com/problems/palindromic-substrings/

//Approach 1 | Bruteforce
bool isPalindrome(const string& s, int left, int right) 
{
    while (left < right) 
    {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int countSubstrings(string s) 
{
    int count = 0;
    for (int i = 0; i < s.length(); ++i) 
    {
        for (int j = i; j < s.length(); ++j) 
        {
            if (isPalindrome(s, i, j)) 
            {
                count++;
            }
        }
    }
    return count;
}

//O(n^3)
//O(1)



//Approach 2 | DP
int countSubstrings(string s) 
{
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int count = 0;

    // Every single character is a palindrome
    for (int i = 0; i < n; ++i) 
    {
        dp[i][i] = true;
        count++;
    }

    // Check for palindromic substrings of length 2
    for (int i = 0; i < n - 1; ++i) 
    {
        if (s[i] == s[i + 1]) 
        {
            dp[i][i + 1] = true;
            count++;
        }
    }

    // Check for palindromic substrings of length 3 or more
    for (int len = 3; len <= n; ++len) 
    {
        for (int i = 0; i <= n - len; ++i) 
        {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) 
            {
                dp[i][j] = true;
                count++;
            }
        }
    }

    return count;
}
//O(n^2)
//O(n^2)

