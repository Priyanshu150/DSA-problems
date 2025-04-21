#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)          
// Space complexity :- O(1)              

// Approach :- 
// if we find the xorr value of (arr[i] & i) then we get our dupplicate number
// because every number will occur twice expcept duplicate one which will occur thrice


// Links :- https://www.geeksforgeeks.org/problems/find-repetitive-element-from-1-to-n-1/1

class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        int res = 0, n = arr.size();
        
        for(int i=0; i<n; ++i)
            res ^= (arr[i]^i);
        
        return res;
    }
};