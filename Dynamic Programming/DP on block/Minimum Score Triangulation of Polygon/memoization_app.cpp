#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N^3)
//Space complexity :- O(N*N + O(N)) 

// Approach :-
// Fixed two of the extreme side of the polygon as they are circular they will meet 
// and take each point as third and try creating all the possibilities 
// basicially here we'll try all possibilities i.e. recursion f(i, j)
// If we select any point the polygon on left and right side will be our sub-problem 
// using for loop try the third point and then use it to recusion f(i, k) + f(k, j)
// only 1 or 2 side are given then triangle cannot be formed if(i+1 == j)   return 0;
// caluclate the min operation for all possibilities that will be our answer 
// since only 2 parameter are changing we can memoize this using 2-d dp


//link :- https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

class Solution {
private:
    int helper(int i, int j, vector<int> &values, vector<vector<int>> &dp){
        // only 1 or 2 side are given then triangle cannot be formed
        if(i+1 == j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        int res = INT_MAX;
        for(int k=i+1; k<j; ++k){
            int opn = values[i]*values[j]*values[k] + helper(i, k, values, dp) + helper(k, j, values, dp);
            res = min(res, opn);
        }
        return dp[i][j] = res;
    }

public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(0, n-1, values, dp);
    }
};