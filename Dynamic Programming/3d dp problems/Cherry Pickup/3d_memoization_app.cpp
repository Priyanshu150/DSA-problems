#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n*n)  
// Space complexity :- O(n*n*n + aux_stack)

// Approach :-  
// we can further reduce the states to 3, using equation r1+c1 = r2+c2
// using the same logic, we can reduce one state 

// Link :- 
// leetcode :- https://leetcode.com/problems/cherry-pickup/description/
// gfg :- https://www.geeksforgeeks.org/problems/chocolate-pickup-ii/1

class Solution {
private:
    int n;
     int dp[51][51][51];

    int solve(int r1, int c1, int c2, vector<vector<int>> &grid){
        int r2 = r1 + c1 - c2;
        if(r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1){
            return -1e5;
        }
        if(r1 == n-1 && c1 == n-1)
            return grid[r1][r2];

        int &ans = dp[r1][c1][c2];
        if(ans != -1)       return ans;
        
        int cherries = 0;
        if(r1 == r2 && c1 == c2)
            cherries += grid[r1][c1];
        else 
            cherries += (grid[r1][c1] + grid[r2][c2]);
        
        // both moves to the right 
        int opn1 = solve(r1, c1+1, c2+1, grid);
        // one moves right and other moves to down
        int opn2 = solve(r1, c1+1, c2, grid);
        // one moves down and other moves to right
        int opn3 = solve(r1+1, c1, c2+1, grid);
        // both of them moves to down 
        int opn4 = solve(r1+1, c1, c2, grid);

        cherries += max({opn1, opn2, opn3, opn4});
        return ans = cherries;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        // Instead of 1 person, assume 2 person starting from top-left to bottom-right 
        memset(dp, -1, sizeof(dp));
        int val = solve(0, 0, 0, grid);
        return (val < 0) ? 0 : val;
    }
};