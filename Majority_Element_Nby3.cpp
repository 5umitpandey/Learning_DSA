//https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/majority-vote

vector<int> findMajority(vector<int>& arr) 
    {
        int n = arr.size();
        unordered_map<int, int> countMap;
        unordered_set<int> added;
        
        for (int num : arr) 
        {
            countMap[num]++;
        }
    
        vector<int> result;
        for (int num : arr) 
        {
            if (countMap[num] > n / 3 && added.find(num) == added.end() ) 
            {
                result.push_back(num);
                added.insert(num);
            }
        }
        
        sort( result.begin(), result.end());
        return result;
    }
