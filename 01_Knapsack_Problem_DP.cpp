// 0/1 Knapsack problem

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) 
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) 
    {
        for (int w = 0; w <= W; ++w) 
        {
            if (weights[i - 1] <= w) 
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } 
            else 
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int C = 7;  
    vector<int> profit = {5, 3, 8, 6};  
    vector<int> weight = {2, 3, 4, 5};  
    int n = weight.size();  

    int max_value = knapsack(C, weight, profit, n);
    cout << max_value << endl;

    return 0;
}