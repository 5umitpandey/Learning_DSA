int doUnion(vector<int> arr1, vector<int> arr2) 
{
    // code here
    set<int> uni( arr1.begin(), arr1.end() );
    
    uni.insert(arr2.begin(), arr2.end());
    
    return uni.size();
}