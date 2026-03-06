#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(N^4)
// Space complexity :- O(N^3)

// Approach :-   
// since the array is sorted we can take any node as root 
// and left subarray will form the left subtree and right subarray will form right subtree
// we'll use recursion to generate all the subtree 
// the parameter will be (i, j, level) 
// we'll traverse from i to j and find the cost of the tree and then call the recursion for rest 
// i.e f(i, ind-1) + f(ind+1, j) + curr_cost
// min of all the possibilities will be our answer 
// we can memoize this solution using 3-d dp 

//Link :- https://www.geeksforgeeks.org/problems/optimal-binary-search-tree2214/1

class Solution {
  private:
    int solve(int i, int j, int level, vector<int> &keys, vector<int> &freq){
        if(i > j)
            return 0;
        
        int res = INT_MAX;
        
        for(int ind=i; ind<=j; ++ind){
            int cost = freq[ind]*level + solve(i, ind-1, level+1, keys, freq) 
                + solve(ind+1, j, level+1, keys, freq);
            
            res = min(res, cost);
        }
        return res;
    }
  
  public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = freq.size();
        return solve(0, n-1, 1, keys, freq);
    }
};

// memoizaton for the same 
class Solution {
  private:
    vector<vector<vector<int>>> dp;
    
    int solve(int i, int j, int level, vector<int> &keys, vector<int> &freq){
        // base case 
        if(i > j)
            return 0;
            
        // memoize
        int &ans = dp[i][j][level];
        if(ans != -1)
            return ans;
        
        int res = INT_MAX;
        // loop from i to j 
        for(int ind=i; ind<=j; ++ind){
            // find the current node cost 
            int cost = freq[ind]*level + solve(i, ind-1, level+1, keys, freq) 
                + solve(ind+1, j, level+1, keys, freq);
            // update the min answer 
            res = min(res, cost);
        }
        return ans = res;
    }
  
  public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = freq.size();
        // intialize 3d dp with -1
        dp = vector<vector<vector<int>>> (n, vector<vector<int>> (n, vector<int> (n+1, -1)));
        // call recursion 
        return solve(0, n-1, 1, keys, freq);
    }
};