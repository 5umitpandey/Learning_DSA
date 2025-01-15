//https://leetcode.com/problems/minimize-xor/?envType=daily-question&envId=2025-01-15


    int countSetBits(int n) 
    { 
        int count = 0;
        while (n) 
        { 
            n &= (n - 1); 
            count++; 
        } 
        
        return count;
    }

    int minimizeXor(int num1, int num2) 
    {
        int SetBits = countSetBits(num2);
        int result = 0;

        for (int i = 31; i >= 0 && SetBits > 0; --i)
        { 
            if (num1 & (1 << i)) 
            { 
                result |= (1 << i); 
                SetBits--; 
            } 
        } 
        for (int i = 0; i <= 31 && SetBits > 0; ++i) 
        { 
            if (!(result & (1 << i))) 
            { 
                result |= (1 << i); SetBits--; 
            } 
        } 
        return result;
    }
