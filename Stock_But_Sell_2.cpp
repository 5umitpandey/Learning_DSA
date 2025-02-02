//https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/buy-stock-2
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/1528956156/

// Approach 1
int maxProfit(vector<int>& prices) 
    {
        bool is_sorted_desc = true;
        for (int i = 1; i < prices.size(); i++) 
        {
            if (prices[i] > prices[i - 1]) 
            {
                is_sorted_desc = false;
                break;
            }
        }
        if (is_sorted_desc) 
        {
            return 0;
        }
        
        int mp = 0; 
        for(int i=0; i<prices.size() - 1; i++)
        {   
            int profit = 0;
            for(int j=i+1; j<prices.size(); j++)
            {
                profit = prices[j] - prices[i];
                mp = max(mp, profit);
            }
        }

        return mp;
    }
//O(n^2)


// Approach 2
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
//O(n)
