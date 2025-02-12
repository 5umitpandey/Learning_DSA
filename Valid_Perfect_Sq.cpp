//https://leetcode.com/problems/valid-perfect-square/

bool isPerfectSquare(long long n)
{
    long l = 1;
    long long r = n;
    
    while( l <= r )
    {
        long long m = (l + r) / 2;
        long long m_sq = m * m;
        
        if( n == m_sq )
        {
            return true;
        }
        else if( m_sq < n )
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return false;
}
//O(log n)
//O(1)
