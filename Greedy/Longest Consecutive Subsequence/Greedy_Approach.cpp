#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        sort(arr.begin(), arr.end());
        int res = 1, n = arr.size(), lcs = 1, prev = arr[0];
        
        for(int i=1; i<n; ++i){
            if(arr[i] == prev)      continue;
            else if(prev+1 == arr[i])       lcs++;
            else        lcs = 1;
            
            prev = arr[i];
            res = max(res, lcs);
        }
        return res;
    }
};