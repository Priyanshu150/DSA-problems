#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N^3)
//Space complexity :- O(N^2 + N) 

// Approach :-
// For handling the edge case of selecting i-1 and i+1 element at 1 to front and back of the array 
// If we start from the top where all the ballon are present then we'll not get independent sub-problems 
// so we'll start from bottom that means we'll select the last ballon to burst 
// then second last until first one, that way we'll get the independent sub-problems 
// we'll start will (1, n) as the whole range i.e (i, j)
// and we can try looping on all the b/w k=i to j 
// opn will be arr[i-1]*arr[k]*arr[j+1], sub-problem will be f(i, ind-1) + f(ind+1, j)
// base case will be whenever (i > j)   return 0;
// there are 2 changing parameter so 2-d dp will work

//link :- https://leetcode.com/problems/burst-balloons/description/

class Solution {
private:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i > j)       return 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        int res = 0;
        for(int ind=i; ind<=j; ++ind){
            int val = nums[i-1] * nums[ind] * nums[j+1] + solve(i, ind-1, nums, dp) + solve(ind+1, j, nums, dp);
            res = max(res, val);
        }
        return dp[i][j] = res;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+2, vector<int> (n+2, -1));
        return solve(1, n, nums, dp);
    }
};