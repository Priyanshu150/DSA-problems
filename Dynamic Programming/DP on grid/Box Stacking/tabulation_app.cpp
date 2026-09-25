#include <bits/stdc++.h>
using namespace std;

// Time complexity :- O(n^2)
// Space complexity :- O(n)

// Approach :- 
// convert the memoization solution to tabulation solution


//Link :- https://www.geeksforgeeks.org/problems/box-stacking/1

class Solution {
  private:
    bool check(int ind1, int ind2, vector<vector<int>> &boxes){
        return (boxes[ind1][0] > boxes[ind2][0] && boxes[ind1][1] > boxes[ind2][1]);
    }
    
  public:
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        int n = height.size();
        
        vector<vector<int>> boxes;
        
        
        for(int i=0; i<n; ++i){
            int a = height[i];
            int b = width[i];
            int c = length[i];
            
            // build all the valid boxes 
            boxes.push_back({a, b, c});
            boxes.push_back({a, c, b});
            boxes.push_back({b, a, c});
            boxes.push_back({b, c, a});
            boxes.push_back({c, a, b});
            boxes.push_back({c, b, a});
        }
        
        // Sort the boxes in descending order of length and width.
        sort(boxes.begin(), boxes.end(), [](auto &box1, auto &box2) {
            if (box1[0] == box2[0]) {
                if (box1[1] == box2[1]) 
                    return box1[2] > box2[2];
                else 
                    return box1[1] > box2[1];
            }
            return box1[0] > box2[0];
        });
        
        int ans = 0;
        int sz = boxes.size();
        vector<int> dp(sz, -1);
        
        // start with every box as start point 
        for(int ind=sz-1; ind>=0; --ind){
            dp[ind] = boxes[ind][2];    // default height if ending at current box 
        
            for(int j=ind+1; j<sz; ++j){
                if(check(ind, j, boxes)){
                    // try all ways to build maximum height 
                    int maxHeight = boxes[ind][2] + dp[j];
                    dp[ind] = max(maxHeight, dp[ind]);
                }
            }
            ans = max(dp[ind], ans);
        }
        return ans;
    }
};