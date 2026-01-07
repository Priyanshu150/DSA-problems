#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*m*4^m)
//Space complexity :- O((m+n)*2^m)

// Approach :-
// row constraint is max 5, hence we can generate all the ways to color first column and save it 
// for every column, try to painting with the pattern which we generated 
// satisfying the condition that two color should not repeat adjacent 
// hence we can try all the posibilities for coloring and count the ways 

//link :- https://leetcode.com/problems/painting-a-grid-with-three-different-colors/

class Solution {
private:
    vector<vector<int>> dp;
    vector<string> columnStates;
    int mod = 1e9 + 7, totalStates;

    void fillColumn(int rowLeft, string filledColor, char prevColor){
        // base case 
        if(rowLeft == 0){
            // add current combination into the array 
            columnStates.push_back(filledColor);
            return;
        }

        for(auto ch : {'R', 'G', 'B'}){
            // skip painting same color 
            if(prevColor == ch)
                continue;

            // try out all ways 
            fillColumn(rowLeft-1, filledColor + ch, ch);
        }
    }

    int solve(int colLeft, int prev, int m){
        // base case 
        if(colLeft == 0){
            return 1;
        }
        // memoization 
        if(dp[colLeft][prev] != -1)
            return dp[colLeft][prev];
        
        int ways = 0;
        string prevPattern = columnStates[prev];    // previous selected pattern 

        for(int i=0; i<totalStates; ++i){
            string nextPattern = columnStates[i];   // next selected pattern 

            // skip the exact same pattern 
            if(nextPattern == prevPattern)
                continue;

            bool isValid = true; 

            // check if same color repeats of not 
            for(int row=0; row<m; ++row){
                if(prevPattern[row] == nextPattern[row]){
                    isValid = false;
                    break;
                }
            }
            if(isValid){
                // paint with current pattern and move to painting next 
                ways = (ways + solve(colLeft-1, i, m)) % mod;
            }
        }
        return dp[colLeft][prev] = ways % mod;
    }

public:
    int colorTheGrid(int m, int n) {
        columnStates.clear();
        // find all possible ways to color a column 
        fillColumn(m, "", '#');

        totalStates = columnStates.size();
        // initialize the dp array 
        dp = vector<vector<int>> (n, vector<int> (totalStates, -1));

        int res = 0;
        // choose a pattern from all different option to paint the first column 
        for(int i=0; i<totalStates; i++){
            res = (res + solve(n-1, i, m)) % mod;
        }
        return res;
    }
};