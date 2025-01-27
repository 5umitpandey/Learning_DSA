//https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/add-binary-strings3805

string addBinary(string& s1, string& s2) 
    {
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int carry = 0;
        string result = "";
    
        while (i >= 0 || j >= 0 || carry) 
        {
            int sum = carry;
    
            if (i >= 0) {
                sum += s1[i--] - '0';
            }
            if (j >= 0) {
                sum += s2[j--] - '0';
            }
    
            carry = sum / 2;
            result += (sum % 2) + '0';
        }

        reverse(result.begin(), result.end());
    
        int start = 0;
        while (start < result.size() && result[start] == '0') 
        {
            ++start;
        }
        if (start == result.size()) 
        {
            return "0";
        }
    
        return result.substr(start);
    }
