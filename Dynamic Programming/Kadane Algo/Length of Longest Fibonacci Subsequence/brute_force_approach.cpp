#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^3)
// Space Complexity: O(n^2 + n)

// Approach :- 
// If we fix two pair of number we can easily find the 3rd number using a+b = c
// Let's fix b&c and for finding a store index with element in a hash map table
// as long as we find the number we find previous number we add 1 and call recursion to solve rest 
// we can return 2 if the previous number is not found any ways we'll have 2 length for any pair 
// there are 2 changing parameter hence we can memoize it using 2-d dp 

// Link :- https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

class Solution {
private:
    int solve(int j, int k, vector<int> &arr, unordered_map<int,int> &mp, vector<vector<int>> &dp){
        if(dp[j][k] != -1)
            return dp[j][k];

        int target = arr[k] - arr[j];
        if(mp.count(target) && mp[target] < j){
            return dp[j][k] = solve(mp[target], j, arr, mp, dp) + 1;
        }
        return dp[j][k] = 2;
    }

public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), max_length = 0;
        unordered_map<int, int> mp;
        vector<vector<int>> dp(n, vector<int> (n, -1));

        // mapping the element with index
        for(int i=0; i<n; ++i)
            mp[arr[i]] = i;
        
        // trying all possible pair of 2 elements 
        for(int j=1; j<n; ++j){
            for(int k=j+1; k<n; ++k){
                int length = solve(j, k, arr, mp, dp);
                if(length >= 3){
                    max_length = max(max_length, length);
                }
            }
        }
        return max_length;
    }
};