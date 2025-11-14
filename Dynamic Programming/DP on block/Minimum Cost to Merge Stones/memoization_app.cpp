#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*n*n)               
// Space complexity :- O(n*n + n(stack_space))      

// Approach :-
// we've to try all possibilities to solve this problem greedy will not work here
// not possible case -> total stones has to removed will be n-1 only 1 remains at last 
// and in each step we're removing k-1 stone hence (n-1) has to be divided by (k-1) for a solution to exits 
// we'll use partition dp to solve this problem, states will be (0, n-1) 
// try creating every partion using loop from ind = i to j-1 by skiping k-1 
// and partition it f(i, ind) + f(ind+1, j), sum of both will be our answer 
// maintain the minimum value accross all the combination 
// for adding the current contribution of stones score, maintain a prefix sum array 
// using that find the current contribution of the element and add it to our answer 
// since only 2 states are changing we can memoize the solution with 2d dp 

// Links :- 
// gfg - https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// leetcode - https://leetcode.com/problems/minimum-cost-to-merge-stones/description/

class Solution {
  private:
    vector<int> prefixSum;
    vector<vector<int>> dp;
    
    int solve(int i, int j, int &k){
        // base case 
        if(i >= j)      return 0;
        // memoization 
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int res = INT_MAX;
        
        // try to make every valid partitions 
        for(int ind=i; ind<j; ind+=(k-1)){
            int cost = solve(i, ind, k) + solve(ind+1, j, k);
            res = min(cost, res);
        }
        // add the contribution of current k consecutive numbers 
        if((j-i) % (k-1) == 0){
            int sum = prefixSum[j+1] - prefixSum[i];
            if(res != INT_MAX)
                res += sum;
        }
        return dp[i][j] = res;
    }
  
  public:
    int mergeStones(vector<int> &stones, int k) {
        // code here
        int n = stones.size();
        
        // not possible case -> total stones has to removed will be n-1
        // and in each step we're removing k-1 stone hence remainder should be 0
        if((n-1) % (k-1) != 0)
            return -1;
        
        // initailize 2d dp array 
        dp.resize(n, vector<int> (n, -1));
        // intialize prefix sum array with n+1 size 
        prefixSum.resize(n+1, 0);
        
        // maintain prefix sum
        for(int i=0; i<n; ++i){
            prefixSum[i+1] = prefixSum[i] + stones[i];
        }
        
        // try-out all ways using recursion 
        return solve(0, n-1, k);
    }
};