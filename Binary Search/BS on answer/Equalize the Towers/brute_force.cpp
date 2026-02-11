#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N^2)
// Space complexity :- O(1)

// Approach :-  
// fixed one of the height from the array 
// conver all the rest of the building to that height and calculate the cost 
// repeat this to every height present in the array 


// Link :- https://www.geeksforgeeks.org/problems/equalize-the-towers2804/

class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size(), res = INT_MAX;
        
        // traverse on each tower heights 
        for(int i=0; i<n; ++i){
            // fixed the size of current tower as reference 
            int fixedHeight = heights[i], newCost = 0;
            
            // convert all the heights of tower to fixed height 
            for(int j=0; j<n; ++j){
                // find the cost to convert all the tower 
                int diff = abs(fixedHeight - heights[j]);
                newCost += (diff * cost[j]);
            }
            // update the min cost for the each fixed height 
            res = min(res, newCost);
        }
        return res;
    }
};