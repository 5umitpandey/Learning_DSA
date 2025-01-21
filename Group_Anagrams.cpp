//https://leetcode.com/problems/group-anagrams/?envType=daily-question&envId=2025-01-21

vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> anagramMap;

        for (string& str : strs) 
        {
            string key = str;
            sort(key.begin(), key.end());

            anagramMap[key].push_back(str);
        }

        vector<vector<string>> result;
        for (auto& entry : anagramMap) 
        {
            result.push_back(entry.second);
        }

        return result;    
    }
