#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(3*2)

// Approach1 :-
// we use the space optimized solution of stock buy and sell - max k trnsn
// We've to just pass k = 2 in that solution and we'll get our answer

// Approach2 :- 
// Extending the previous approach, since k = 2 intead of writing a loop we write the condition twice
// once for 1 and other time for 2, and we're good
// changing the code accordingly we'll get our solution


//link :- https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1

//Approach 1 
class Solution {
  private:
    int solve(vector<int> &prices, int k){
        int n = prices.size();
        vector<vector<int>> ahead(k+1, vector<int> (2, 0)), curr = ahead;
        
        for(int ind=n-1; ind>=0; --ind){
            for(int cap=1; cap<=k; ++cap){
                curr[cap][1] = max(ahead[cap][1], -prices[ind] + ahead[cap][0]);
                curr[cap][0] = max(ahead[cap][0], prices[ind] + ahead[cap-1][1]);
            }
            ahead = curr;
        }
        return ahead[k][1];
    }
  
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        return solve(prices, 2);
    }
};

// Approach 2
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> ahead(3, vector<int> (2, 0)), curr = ahead;
        
        for(int ind=n-1; ind>=0; --ind){
            curr[1][1] = max(ahead[1][1], -prices[ind] + ahead[1][0]);
            curr[1][0] = max(ahead[1][0], prices[ind] + ahead[0][1]);
            curr[2][1] = max(ahead[2][1], -prices[ind] + ahead[2][0]);
            curr[2][0] = max(ahead[2][0], prices[ind] + ahead[1][1]);
            ahead = curr;
        }
        return ahead[2][1];
    }
};