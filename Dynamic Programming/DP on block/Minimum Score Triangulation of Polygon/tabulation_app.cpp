#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N^3)
//Space complexity :- O(N*N) 

// Approach :-
// Only 2 state are changing i.e i & j 
// for the base case all the value assign to 0, represent a general approach
// for the i will go from n-3 to 0 (we'll leave 2 value otherwise triangle will not be formed)
// and j = i+2 to n (again leaving 2 values from starting)
// next copy the recurence and the answer will be stored at dp[0][n-1] which we were calling for recusion 


//link :- https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));

        for(int i=n-3; i>=0; --i){
            for(int j=i+2; j<n; ++j){
                int res = INT_MAX;
                for(int k=i+1; k<j; ++k){
                    int opn = values[i]*values[j]*values[k] + dp[i][k] + dp[k][j];
                    res = min(res, opn);
                }
                dp[i][j] = res;
            }
        }
        return dp[0][n-1];
    }
};

