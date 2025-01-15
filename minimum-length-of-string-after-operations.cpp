//https://leetcode.com/problems/minimum-length-of-string-after-operations/?envType=daily-question&envId=2025-01-13

int minimumLength(string s)
    {   
        vector <int> CharFreq(26, 0);
        int TotalLen = 0;

        for( char CurrentChar : s )
        {
            CharFreq[ CurrentChar - 'a' ]++;
        }

        for( int Freq : CharFreq )
        {
            if( Freq == 0 ) continue;
            if( Freq % 2 == 0 )
            {
                TotalLen += 2;
            }
            else
            {
                TotalLen += 1;
            }
        }

        return TotalLen;
    }
