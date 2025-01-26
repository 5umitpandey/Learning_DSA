//https://leetcode.com/problems/convert-1d-array-into-2d-array/description/?envType=daily-question&envId=2025-01-26

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        if (original.size() != m * n) 
        {
            return {};
        }

        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < original.size(); ++i) 
        {
            result[i / n][i % n] = original[i];
        }

        return result;    
    }
