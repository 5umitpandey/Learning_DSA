//https://leetcode.com/problems/fraction-addition-and-subtraction/?envType=daily-question&envId=2025-01-19

string fractionAddition(string expression) 
    {
        int num = 0, den = 1;
        istringstream ss(expression);
        int n, denom;

        while( ss >> n )
        {
            ss.ignore(1);
            ss >> denom;

            num = num * denom + n * den;
            den *= denom;

            int div = abs( gcd(num, den) );
            num /= div;
            den /= div;
        }

        if( den < 0 )
        {
            num = -num;
            den = -den;
        }

        return to_string(num) + "/" + to_string(den);
    }
