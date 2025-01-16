//https://leetcode.com/problems/bitwise-xor-of-all-pairings/?envType=daily-question&envId=2025-01-16

int xorAllNums(vector<int>& num1, vector<int>& num2) 
{
        
        int Xor1 = 0, Xor2 = 0;

        for(int num : num1 )
            Xor1 ^= num;

        for(int num : num2 )
            Xor2 ^= num;

        int len1 = num1.size();
        int len2 = num2.size();

        if( len1 % 2 == 0 && len2 % 2 == 0 )
        {
            return 0;
        }
        else if( len1 % 2 == 1 && len2 % 2 == 0 )
        {
            return Xor2;
        }
        else if( len1 % 2 == 0 && len2 % 2 == 1 )
        {
            return Xor1;
        }
        else
        {
            return Xor1 ^ Xor2;
        }
    }
