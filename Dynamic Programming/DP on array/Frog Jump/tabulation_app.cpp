#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(n)

// Approach :-
// we've try out all the ways in this problem, hence we'll use dynamic programming 
// For tabulation approach, the base case will be dp[n-1] = 0, and dp[n-2] = abs(arr[n-1] - arr[n-2])
// for every index from n-3 to 0, we can check wheater one or two jump is giving me min value
// and update that in the current value of dp table
// answer will be stored at dp[0]

//link :- https://www.geeksforgeeks.org/problems/geek-jump/1

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        if(n == 1)
            return 0;
            
        vector<int> dp(n);
        dp[n-1] = 0;
        dp[n-2] = abs(height[n-1] - height[n-2]);
        
        for(int i=n-3; i>=0; --i){
            int oneJump = dp[i+1] + abs(height[i] - height[i+1]);
            int twoJump = dp[i+2] + abs(height[i] - height[i+2]);
            dp[i] = min(oneJump, twoJump);
        }
        return dp[0];
    }
};