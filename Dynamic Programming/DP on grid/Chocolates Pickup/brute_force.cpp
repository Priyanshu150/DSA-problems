#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(6^(n*m*m))
// Space Complexity: O(1)

// Approach :- 
// we've to try to explore all the possibilites for the two robots 
// use recursion to achieve the same, express both the robot movement in one function 
// (row, col1, col2) will be the changing parameter for robot, row for both can be combined as they both will share common row
// this is because they will move in single direction and will now change row at any point of time 
// base case will be when we reach at the last row return the value depending on wheather they are standing on different or same cell
// there will total of 9 possiblities for both robot movement, use loop to express the same
// take max of all posssible ways which will be our answer 
// count the contribution of cells only once depending on which cells they are standing on 

// Link :- https://www.geeksforgeeks.org/problems/chocolates-pickup/1

class Solution {
  private:
    int n, m;
    
    bool isValid(int col1, int col2){
        return (col1 >= 0 && col1 < m && col2 >= 0 && col2 < m);
    }
    
    int solve(int row, int col1, int col2, vector<vector<int>> &grid){
         int value = 0, res = 0;
        
        if(col1 == col2){
            value = grid[row][col1];
        }
        else{
            value = grid[row][col1] + grid[row][col2];
        }
        
        // base case 
        if(row == n-1){
            return value;
        }
        
        for(int c1=-1; c1<=1; ++c1){
            for(int c2=-1; c2<=1; ++c2){
                int ncol1 = col1 + c1;
                int ncol2 = col2 + c2;
                
                if(isValid(ncol1, ncol2)){
                    int newVal = solve(row+1, ncol1, ncol2, grid);
                    res = max(res, newVal + value);
                }
            }
        }
        return res;
    }
  
  public:
    int maxChocolate(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        return solve(0, 0, m-1, grid);
    }
};