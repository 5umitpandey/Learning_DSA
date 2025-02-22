//dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1]

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainMultiplication(const vector<int>& p) 
{
    int n = p.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0)); 

    for (int length = 2; length <= n; ++length) 
    {
        for (int i = 0; i < n - length + 1; ++i) 
        {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) 
            {
                int q = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < dp[i][j]) 
                {
                    dp[i][j] = q;
                }
            }
        }
    }
    return dp[0][n - 1];
}


int main()
{
    vector<int> p = {2, 1, 3, 4};
    cout << matrixChainMultiplication(p) << endl;
    return 0;
}
