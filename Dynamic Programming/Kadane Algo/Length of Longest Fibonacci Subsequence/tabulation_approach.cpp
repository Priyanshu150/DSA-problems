#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n^2 + n)

// Approach :- 
// converting brute_force recursion to tabulation
// base case will be every pair having length of 2 because they anways follow the series 
// logic remains same we find the previous index and update the maximum length and store it in dp table
// we maintain a max_length which is only updated when the length increases from 3 

// Link :- https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), max_length = 0;
        unordered_map<int, int> mp;
        // base case that every pair will be forming 2 length series 
        vector<vector<int>> dp(n, vector<int> (n, 2));

        // mapping the element with index
        for(int i=0; i<n; ++i)
            mp[arr[i]] = i;
        
        // trying all possible pair of 2 elements 
        for(int j=1; j<n; ++j){
            for(int k=j+1; k<n; ++k){
                // Find the target 
                int target = arr[k] - arr[j];

                // Seraching in the map for previous index of target 
                if(mp.count(target) && mp[target] < j){
                    dp[j][k] = dp[mp[target]][j] + 1;
                }
                if(dp[j][k] >= 3){
                    max_length = max(max_length, dp[j][k]);
                }
            }
        }
        return max_length;
    }
};