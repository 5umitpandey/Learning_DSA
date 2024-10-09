/*
Input:
a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
a2[] = {11, 3, 7, 1, 7}
Output:
Yes

Input:
a1[] = {10, 5, 2, 23, 19}
a2[] = {19, 5, 3}
Output:
No
*/

string isSubset(int a1[], int a2[], int n, int m) 
{   
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) 
    {
        freq[a1[i]]++;
    }

    // Check if all elements of the second array are present in the map
    for (int i = 0; i < m; i++) 
    {
        if(freq[a2[i]] > 0) 
        {
            freq[a2[i]]--;
        }
        else 
        {
            return "No";
        }
    }
    return "Yes";
}
