//https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/implement-atoi

int myAtoi(char *s) 
    {
        int i = 0;
        int sign = 1;
        int result = 0;
    
        // whitespaces
        while (s[i] == ' ') {
            i++;
        }
    
        // sign
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
    
        // leading zeros
        while (s[i] == '0') {
            i++;
        }
    
        // Convert & characters
        while (s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
    
            // overflow and underflow
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
    
            result = result * 10 + digit;
            i++;
        }
    
        return result * sign;    
    }
