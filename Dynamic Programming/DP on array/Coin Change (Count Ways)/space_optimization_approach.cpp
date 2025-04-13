#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*S)  
// Space complexity :- O(S)

// Approach :-
// WE can further optimize the space from tabulation approach 
// since we're only using previous row for the current row
// that way 1-d array will suffice the solution 

// Link :- https://www.geeksforgeeks.org/problems/coin-change2448/1

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<int> prev(sum+1, 0), curr(sum+1, 0);
        prev[0] = 1;
        
        for(int ind=1; ind<=n; ++ind){
            curr[0] = 1;
            for(int s=1; s<=sum; ++s){
                curr[s] = prev[s];
                if(coins[ind-1] <= s)
                    curr[s] += curr[s-coins[ind-1]];
            }
            prev = curr;
        }
        return prev[sum];
    }
};


class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<int> prev(sum+1, 0), curr(sum+1, 0);
        
        for(int s=0; s<=sum; ++s){
            if(s % coins[0] == 0)
                prev[s] = 1;
        }
        
        for(int ind=1; ind<n; ++ind){
            curr[0] = 1;
            for(int s=1; s<=sum; ++s){
                curr[s] = prev[s];
                
                if(coins[ind] <= s)
                    curr[s] += curr[s-coins[ind]];
            }
            prev = curr;
        }
        return prev[sum];
    }
};
