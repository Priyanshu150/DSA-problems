#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*n*n)
//Space complexity :- O(n*1001*n), where n is for stack space 

// Approach :-
// we'll first pick the 2 number and find the difference among them 
// using that difference we'll find all the number with that diff 
// and try to maximize the sequence by trying all possibilites 
// since only 2 state is changing i.e ind & diff we can meoize the solution using 2-d dp
// maintain a variable to store max answer
// take diff + 500 to avoid the overflow, Since the number can be negative according to constraints


//link :- https://leetcode.com/problems/longest-arithmetic-subsequence/

class Solution {
private:
    int solve(int ind, int diff, vector<int> &nums, vector<vector<int>> &dp){
        if(ind == 0)    return 0;
        if(dp[ind][diff] != -1)     return dp[ind][diff];

        int res = 0;
        for(int k=0; k<ind; ++k){
            int currDiff = nums[ind] - nums[k] + 500;
            if(currDiff == diff){
                res = max(res, 1 + solve(k, diff, nums, dp));
            }
        }
        return dp[ind][diff] = res;
    }

public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)      return n;

        int ans = 0;
        vector<vector<int>> dp(n, vector<int> (1001, -1));

        for(int i=1; i<n; ++i){
            for(int j=0; j<i; ++j){
                int diff = nums[i] - nums[j] + 500;
                ans = max(ans, 2 + solve(j, diff, nums, dp));
            }
        }
        return ans;
    }
};