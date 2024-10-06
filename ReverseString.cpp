//O(n)
string reverseString(string& s) 
{
    string rs = "";
    for (int i = s.length() - 1; i >= 0; i--) 
    {
        rs += s[i];
    }
    return rs;
}

//O(1)
string reverseString(string& s) 
{
    // Your code goes here
    reverse(s.begin(), s.end());
    
    return s;
}
