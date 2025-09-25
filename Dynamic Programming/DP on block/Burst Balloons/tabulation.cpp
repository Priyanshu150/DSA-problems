#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N^3)
//Space complexity :- O(N^2) 

// Approach :-
// Initialize the dp with 0
// i = n to 1 and j= 1 to n 
// copy the recurence case 
// result will be stored at dp[1][n]


//link :- https://leetcode.com/problems/burst-balloons/description/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

        for(int i=n; i>=1; --i){
            for(int j=1; j<=n; ++j){
                if(i > j)   continue;

                for(int ind=i; ind<=j; ++ind){
                    int val = nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1] + dp[ind+1][j];
                    dp[i][j] = max(dp[i][j], val);
                }
            }
        }
        return dp[1][n];
    }
};