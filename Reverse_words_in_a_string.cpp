//https://leetcode.com/problems/reverse-words-in-a-string/

//Bruteforce
    string reverseWords(string s) 
    {
        int n = s.length();
        
        vector <string> words;
        
        int start, end;
        
        int i = 0;
        while(i < n) 
        {
            
            while(i < n && s[i] == ' ') i++;
            
            if(i >= n) break;
            
            start = i;
            
            while(i < n && s[i] != ' ') i++;
            
            end = i-1;
            
            string wordFound = s.substr(start, end-start+1);
            words.push_back(wordFound);
        }
        
        string ans = "";
        
        for(int i = words.size() - 1; i >= 0; i--) 
        {
            ans += words[i];
            
            if(i != 0) ans.push_back(' ');
        }
        
        return ans;
    } 
