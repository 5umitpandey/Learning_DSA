//https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/?envType=daily-question&envId=2025-01-12

bool canBeValid(string s, string locked) 
{
    int n = s.size();
    if (n % 2 != 0) return false; // If the length of the string is odd, it can't be valid

    int open = 0, close = 0;
    
    // First pass: left to right
    for (int i = 0; i < n; i++) 
    {
        if (locked[i] == '0' || s[i] == '(') open++;
        else close++;
        if (close > open) return false; // More closing brackets than opening
    }
    
    open = close = 0;
    
    // Second pass: right to left
    for (int i = n - 1; i >= 0; i--) 
    {
        if (locked[i] == '0' || s[i] == ')') close++;
        else open++;
        if (open > close) return false; // More opening brackets than closing
    }
    
    return true;
}
