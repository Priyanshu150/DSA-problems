#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(n*n)
// Space complexity :- O(n*n + n)

// Approach :-  
// we've to try all ways to collect points for player1 
// player1 will have two option take from start and end 
// there will two states left and right representing first and last element 
// when they exhaust it will be our base case 
// now player 2 will return the min result of the options available as both are playing optimally 
// since only 2 states are changing we'll need 2 dp to memoize this solution 

// Link :- https://leetcode.com/problems/stone-game/description/

class Solution {
  private:
    int findScore(int left, int right, vector<int> &nums, vector<vector<int>> &dp){
        if(left > right)        return 0;
        if(left == right)       return nums[left];
        if(dp[left][right] != -1)  
            return dp[left][right];

        int first = nums[left] + min(findScore(left+2, right, nums, dp), findScore(left+1, right-1, nums, dp));
        int last = nums[right] + min(findScore(left+1, right-1, nums, dp), findScore(left, right-2, nums, dp));

        return dp[left][right] = max(first, last);
    }

public:
    bool stoneGame(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);

        vector<vector<int>> dp(n, vector<int> (n, -1));
        int score1 = findScore(0, n-1, nums, dp);
        return (sum - score1) <= score1;
    }
};