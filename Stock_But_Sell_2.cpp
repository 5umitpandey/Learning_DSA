//https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/buy-stock-2

int maximumProfit(vector<int> &prices) 
    {
        int n = prices.size();
        if (n <= 1) return 0;
    
        int maxProfit = 0;
        int minPrice = INT_MAX;
    
        for (int Price : prices) 
        {
            minPrice = min( minPrice, Price );
            
            maxProfit = max( maxProfit, Price - minPrice);
        }
    
        return maxProfit;
    }
