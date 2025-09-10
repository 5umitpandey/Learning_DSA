//https://leetcode.com/problems/rearrange-array-elements-by-sign/

class Solution {
public:

    //BruteForce
    // vector<int> rearrangeArray(vector<int>& nums) 
    // {   
    //     vector <int> pos;
    //     vector <int> neg;
    //     for(int i=0; i<nums.size(); i++)
    //     {
    //         if( nums[i] > 0 )
    //             pos.push_back(nums[i]);
    //         else
    //             neg.push_back(nums[i]);
    //     }

    //     int p=0, n=0;
    //     for(int i=0; i<nums.size(); i++)
    //     {   
    //         if( i % 2 == 0 )
    //         {
    //             nums[i] = pos[p];
    //             ++p;
    //         }
    //         else
    //         {
    //             nums[i] = neg[n];
    //             ++n;
    //         }
    //     }

    //     return nums;
    // }

    //BetterSpace | BruteForce
    vector<int> rearrangeArray(vector<int>& nums) 
    {   
        vector <int> res(nums.size());
        int p=0, n=1;
        for(int i=0; i<nums.size(); i++)
        {
            if( nums[i] > 0 )
            {
                res[p] = nums[i];
                p += 2;
            }
            else
            {
                res[n] = nums[i];
                n += 2;
            }
        }
        return res;
    }
};
