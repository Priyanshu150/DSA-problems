#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(n)

// Approach :-


// Link :- https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size(), prefixSum = 0, res = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        
        for(int i=0; i<n; ++i){
            prefixSum += (arr[i] > k) ? 1 : -1;
            if(prefixSum > 0)
                res = i+1;
            
            if(mp.count(prefixSum - 1))
                res = max(res, i - mp[prefixSum - 1]);
            
            if(!mp.count(prefixSum))
                mp[prefixSum] = i;
        }
        return res;
    }
};