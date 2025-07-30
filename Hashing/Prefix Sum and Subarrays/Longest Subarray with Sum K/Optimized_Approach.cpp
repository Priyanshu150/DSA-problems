#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N)    

//Approach :-
// Sliding window will not work for this problem because of negative number
// Prefix sum and hashing combined can be used to solve the problem
// The idea is to caluclate the prefix sum till at i 
// For index i, find is their any subarray that have ([sum till index i] - k) valued subarray
// Store the occurence of every first time sum in the mp with index
// Index can help us to calculate the length 
// And First occurence because it will give us the longest length

//link :- https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), sum = 0, res = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        for(int i=0; i<n; ++i){
            sum += arr[i];
            int trgt = sum - k;
            
            if(mp.count(trgt))
                res = max(res,i - mp[trgt]);
            
            if(!mp.count(sum))
                mp[sum] = i;
        }
        return res;
    }
};