#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*3)
// Space complexity :- O(n*3)

// Approach :-  
// convert the memoization into tabulation to reduce the stack space space

//Link :- https://leetcode.com/problems/greatest-sum-divisible-by-three/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        // initalize 2p dp of size n*3 with min value 
        vector<vector<int>> dp(n+1, vector<int> (3, INT_MIN));
        // base case 
        dp[0][0] = 0;

        for(int ind=1; ind<=n; ++ind){
            for(int rem=2; rem>=0; --rem){
                // explore all possibilities
                int notTake = dp[ind-1][rem];
                int take = nums[ind-1] + dp[ind-1][(rem + nums[ind-1])%3];
                // take max of both possibilities
                dp[ind][rem] = max(take, notTake);
            }
        }
        return dp[n][0];
    }
};