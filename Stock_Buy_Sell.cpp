//https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/stock-buy-and-sell2615

int maximumProfit(vector<int> &prices) 
    {
        int n = prices.size();
        if (n <= 1) return 0;
    
        int maxProfit = 0;
    
        for (int i = 1; i < n; i++) 
        {
            if (prices[i] > prices[i - 1]) 
            {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
    
        return maxProfit;
    }
