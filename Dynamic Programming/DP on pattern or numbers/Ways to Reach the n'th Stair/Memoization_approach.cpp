#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N*N)

// Approach :-
// For calulation of number of way to reach n stairs, we can deduce the formula which will be
// calculation till (n-1) step + calculation till (n-2) steps
// we can use recursion to implement the same logic and save the state inorder to eliminate repeating sub-problem
// hence we can use array dp to optimize the repeating sub-problems

//link :- https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1

class Solution {
  private:
    int helper(int num, vector<int> &dp){
        if(num < 4)     return num;
        if(dp[num] != -1)   return dp[num];
        
        return dp[num] =  helper(num-1, dp) + helper(num-2, dp);
    }
  
  public:
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};
