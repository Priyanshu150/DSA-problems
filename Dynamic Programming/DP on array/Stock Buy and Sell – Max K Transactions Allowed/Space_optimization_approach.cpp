#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*k*2)
//Space complexity :- O(k*2)

// Approach :-
// we can further otpimize the space from 3-d to 2-d dp
// since we are only needed the ahead 2-d dp to calcuate our answer
// all the cases remains same from tabulation just only change the 3dp dp to two 2dp array (ahead, curr)

//link :- https://www.geeksforgeeks.org/problems/maximum-profit4657/1


class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        vector<vector<int>> ahead(k+1, vector<int> (2, 0)), curr = ahead;
        
        for(int cap=1; cap<=k; ++cap)
            ahead[cap][0] = prices[n-1];
            
        for(int ind=n-2; ind>=0; --ind){
            for(int cap=1; cap<=k; ++cap){
                curr[cap][1] = max(ahead[cap][1], -prices[ind] + ahead[cap][0]);
                curr[cap][0] = max(ahead[cap][0], prices[ind] + ahead[cap-1][1]);
            }
            ahead = curr;
        }
        return ahead[k][1];
    }
};



class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
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
};

