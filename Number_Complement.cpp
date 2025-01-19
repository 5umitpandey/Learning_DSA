//https://leetcode.com/problems/number-complement/?envType=daily-question&envId=2025-01-18

int findComplement(int num) 
    {   
        if( num < 0 ) return 0;

        unsigned int mask = ~0;
        while(mask & num)
        {
            mask <<= 1;
        }
        return ~num & ~mask;   
    }
