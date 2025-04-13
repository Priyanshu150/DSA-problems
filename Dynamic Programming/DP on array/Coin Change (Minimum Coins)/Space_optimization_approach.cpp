#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*s)  
// Space complexity :- O(s)

// Approach :-  
// we can further optimise the space from tabulation as we only need the previous column of the 2-d dp array
// we'll store only the previous row and current row to caluculate our answer 
// and rest of the approach remains same from the tabulation
// at last we can check if answer points to maxValue then return -1 otherwise answer

// Link :- https://www.geeksforgeeks.org/problems/number-of-coins1824/1


class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size(), maxValue = 1e7+10;
        vector<int> prev(sum+1, maxValue), curr(sum+1, maxValue);
        prev[0] = 0;
        
        for(int ind=1; ind<=n; ++ind){
            curr[0] = 0;
            for(int s=1; s<=sum; ++s){
                curr[s] = prev[s];
                
                if(coins[ind-1] <= s)
                    curr[s] = min(curr[s], 1 + curr[s-coins[ind-1]]);
            }
            prev = curr;
        }
        return (prev[sum] == maxValue) ? -1 : prev[sum];
    }
};

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size(), maxValue = 1e7+10;
       vector<int> prev(sum+1, maxValue), curr(sum+1, maxValue);
        
        for(int s=0; s<=sum; ++s){
            if(s % coins[0] == 0)
                prev[s] = s/coins[0];
        }
        
        for(int ind=1; ind<n; ++ind){
            curr[0] = 0;
            for(int s=1; s<=sum; ++s){
                curr[s] = prev[s];
                
                if(coins[ind] <= s)
                    curr[s] = min(curr[s], 1 + curr[s-coins[ind]]);
            }
            prev = curr;
        }
        return (prev[sum] == maxValue) ? -1 : prev[sum];
    }
};