//https://geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/move-all-zeroes-to-end-of-array0751

void pushZerosToEnd(vector<int> &arr) 
    {
        int count = 0;
     
        for (int i = 0; i < arr.size(); i++) 
        {
            if (arr[i] != 0) 
            {
                swap(arr[i], arr[count]);
                
                count++;
            }
        }
    }
