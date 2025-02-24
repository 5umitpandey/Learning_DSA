//https://leetcode.com/problems/valid-parentheses/description/

//Approach 1 | BruteForce
    // bool isValid(string s) 
    // {
    //     while (true) 
    //     {
    //         bool foundPair = false; // Track if any pair was found and removed
    //         int n = s.length(); // Store initial length before modification

    //         for (int i = 0; i < n - 1; ++i) 
    //         { 
    //             if ((s[i] == '(' && s[i + 1] == ')') ||
    //                 (s[i] == '{' && s[i + 1] == '}') ||
    //                 (s[i] == '[' && s[i + 1] == ']')) 
    //                 {
    //                     s.erase(i, 2);
    //                     foundPair = true;
    //                     break; // Restart loop from the beginning
    //                 }
    //         }

    //         if (!foundPair) 
    //         {
    //             break;
    //         }
    //     }

    //     return s.empty();
    // }
//𝑂(𝑛^2)
//𝑂(1)

    //Approach 2 | Stack
    bool isValid(string s) 
    {
        stack<char> st;
        
        for (char c : s) 
        {
            if (c == '(' || c == '{' || c == '[') 
            {
                st.push(c);
            }
            else 
            {
                if (st.empty()) return false;
                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
//𝑂(𝑛^2)
//𝑂(1)
