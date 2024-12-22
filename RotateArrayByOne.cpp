//https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1?page=1&difficulty=School,Basic&sortBy=submissions

void rotate(vector<int> &arr) 
    {
        if (arr.empty()) return;
        rotate(arr.rbegin(), arr.rbegin() + 1, arr.rend());
    }
