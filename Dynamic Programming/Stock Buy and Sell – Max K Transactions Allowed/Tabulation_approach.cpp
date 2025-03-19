#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*k*2)
//Space complexity :- O(n*k*2)

// Approach :-
// we can further optimize on the space by using tabulation approach 
// ind will go from n-1 to n, cap will go from 1 to k and buy will change from 0 to 1
// express the possibilities case using the same approach used in memoization
// express the base case before running the loop
// the answer will be stored at the last element of array


//link :- https://www.geeksforgeeks.org/problems/maximum-profit4657/1



class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (k+1, vector<int> (2, 0)));
        
        for(int cap=1; cap<=k; ++cap)
            dp[n-1][cap][0] = prices[n-1];
            
        for(int ind=n-2; ind>=0; --ind){
            for(int cap=1; cap<=k; ++cap){
                dp[ind][cap][1] = max(dp[ind+1][cap][1], -prices[ind] + dp[ind+1][cap][0]);
                dp[ind][cap][0] = max(dp[ind+1][cap][0], prices[ind] + dp[ind+1][cap-1][1]);
            }
        }
        return dp[0][k][1];
    }
};

class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (k+1, vector<int> (2, 0)));
        
        for(int ind=n-1; ind>=0; --ind){
            for(int cap=1; cap<=k; ++cap){
                dp[ind][cap][1] = max(dp[ind+1][cap][1], -prices[ind] + dp[ind+1][cap][0]);
                dp[ind][cap][0] = max(dp[ind+1][cap][0], prices[ind] + dp[ind+1][cap-1][1]);
            }
        }
        return dp[0][k][1];
    }
};