//https://leetcode.com/problems/neighboring-bitwise-xor/?envType=daily-question&envId=2025-01-17

bool doesValidArrayExist(vector<int>& derived)
{
        int n = derived.size();

        int xor_sum = 0;

        for(int i=0; i<n; i++)
        {
            xor_sum ^= derived[i];
        }

        return xor_sum == 0;
    }
