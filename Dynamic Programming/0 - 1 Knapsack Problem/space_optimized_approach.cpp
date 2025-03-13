#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*W)  
// Space complexity :- O(W)

// Approach :-
// We can further optimize the tabulation as we are only using previous row of 2d array
// So, we can consider 2 1-d array keeping track of current row and previous row

// Link :- https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<int> prev(W+1, 0), curr(W+1, 0);
        
        for(int w=0; w<=W; ++w){
            if(wt[0] <= w)
                prev[w] = val[0];
        }
        
        for(int ind=1; ind<n; ++ind){
            for(int w=1; w<=W; ++w){
                curr[w] = prev[w];
                
                if(wt[ind] <= w)
                    curr[w] = max(curr[w], val[ind] + prev[w-wt[ind]]);
            }
            prev = curr;
        }
        return prev[W];
    }
};