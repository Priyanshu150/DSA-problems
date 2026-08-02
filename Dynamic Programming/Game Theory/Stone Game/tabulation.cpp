#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(n*n)
// Space complexity :- O(n*n)

// Approach :-  
// express the memoization solution into tabulation
// handle the edge case which result in overflow 

// Link :- https://leetcode.com/problems/stone-game/description/

class Solution {
public:
    bool stoneGame(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);

        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

        for(int i=0; i<n; ++i)
            dp[i][i] = nums[i];
        
        for(int left = n-1; left >= 0; --left){
            for(int right = left+1; right < n; ++right){

                // Guard: clamp indices to valid range
                int l2r  = dp[left+2][right];
                int l1r1 = dp[left+1][right-1];
                int lr2  = (right >= 2) ? dp[left][right-2] : 0; 

                int first = nums[left]  + min(l2r,  l1r1);
                int last  = nums[right] + min(l1r1, lr2);

                dp[left][right] = max(first, last);
            }
        }
        int score1 = dp[0][n-1];
        return (sum - score1) <= score1;
    }
};