#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*m)
// Space complexity :- O(2*m)

// Approach :- 
// instead of sorting we can maintain the height in increasing order 
// we'll keep track of height and col value where it's found into ds 
// at every row, if the prev height are found first update those cell value and mark those visited 
// and then traverse on the cell which are not visited and has hieght as 1, update them 
// find the area using hieght * base base on height and keep track of maximum height 

// Links :- https://leetcode.com/problems/largest-submatrix-with-rearrangements/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;

        vector<pair<int,int>> prevHeights;      // {height, col}

        // traverse on each column 
        for(int row=0; row<n; ++row){
            vector<pair<int,int>> heights;
            vector<bool> vis(m, 0);     // track the visited column

            // traverse on prev heights 
            for(auto [height, col]: prevHeights){
                // if current cell value is 1  
                if(matrix[row][col] == 1){
                    // update the new height 
                    heights.push_back({height+1, col});
                    // mark them as visited
                    vis[col] = true;
                }
            }

            for(int col=0; col<m; ++col){
                // add the cell which is not visited and has a height of 1 
                if(!vis[col] && matrix[row][col] == 1){
                    heights.push_back({1, col});
                }
            }
            int base = 1;

            // for every height already sorted in descreasing order 
            for(auto [height, col]: heights){
                // update the maximum area of rectangle 
                res = max(res, height * base);
                // increase the base with increasing heights 
                base += 1;
            }
            // update the previous heights 
            prevHeights = heights;
        }
        return res;
    }
};