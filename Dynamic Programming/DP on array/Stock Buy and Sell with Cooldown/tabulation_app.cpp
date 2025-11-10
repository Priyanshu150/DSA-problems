#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*2)  
// Space complexity :- O(n*2)

// Approach :-  
// Further optimizing space from memoizatin to tabulation 
// ind => (0 to n-1), buy => (0 to 1)
// use same possibilities from recursion 
// at last the answer will be stored at dp[0][1]

// Link :- https://www.geeksforgeeks.org/problems/buy-stock-with-cooldown/1

class Solution {
  public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        // 1d dp array initialization 
        vector<vector<int>> dp(n+3, vector<int> (2, 0));
        
        // try out all possibilities using loops
        for(int ind=n-1; ind>=0; --ind){
            // option to buy current stock 
                int notBuy = dp[ind+1][1];
                int buyNow = dp[ind+1][0] - arr[ind];
                dp[ind][1] = max(notBuy, buyNow);
                // option to sell current stock 
                int notSell = dp[ind+1][0];
                int sellNow = dp[ind+2][1] + arr[ind];
                dp[ind][0] = max(notSell, sellNow);
        }
        
        return dp[0][1];
    }
};