#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(N*K)
// Space complexity :- O(1)

// Approach :-   
// In order to color the wall with minimum cost, we've to keep track on only 2 color 
// min color val and second min color value in the array, Also keep track of min value index
// for first row find these value 
// from second calculate these value based on sum
// if curr_col == min_val_index, then take second_min otherwise take mini for the sum 
// calculate the same for every row and answer will be the min_value maintain throughout

//Link :- https://www.geeksforgeeks.org/problems/walls-coloring-ii--170647/1

class Solution {
  public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size(), k = costs[0].size();
        // only one color is present and multiple wall has to be painted 
        if(k == 1 && n > 1)
            return -1;
        
        int mini = INT_MAX, secMini = INT_MAX, minInd = -1;
        
        // find min and second min from first row 
        for(int i=0; i<k; ++i){
            if(costs[0][i] < mini){
                secMini = mini;
                mini = costs[0][i];
                minInd = i;
            }else{
                secMini = min(secMini, costs[0][i]);
            }
        }
        // paint each wall one by one 
        for(int i=1; i<n; ++i){
            // find min and second min for every row 
            int mini2 = INT_MAX, secMini2 = INT_MAX, minInd2 = -1;
            
            for(int j=0; j<k; ++j){
                int currCost = costs[i][j] + (j == minInd ? secMini : mini);
                
                if(currCost < mini2){
                    secMini2 = mini2;
                    mini2 = currCost;
                    minInd2 = j;
                }
                else    secMini2 = min(secMini2, currCost);
            }
            // update the variables till now 
            mini = mini2;
            secMini = secMini2;
            minInd = minInd2;
        }
        return mini;
    }
};