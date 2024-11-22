//https://www.geeksforgeeks.org/problems/reverse-array-in-groups0255/1?page=1&difficulty=School,Basic&sortBy=submissions

void reverseInGroups(vector<long long int> &arr, int k) 
    {
        // code here
        int n = arr.size();
        for (int i = 0; i < n; i += k) 
        {
            int left = i;
            int right = min(i + k - 1, n - 1);
            // Reverse the subarray from left to right
            while (left < right) 
            {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
