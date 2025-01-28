//https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/anagram-1587115620

bool areAnagrams(string& s1, string& s2) 
    {
        if (s1.length() != s2.length()) 
        {
            return false;
        }
    
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
    
        return s1 == s2;
    }
