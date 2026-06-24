#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2^(n^2))
// Space complexity :- O(n²)

// Approach :- 
// try out all ways to find a way for the path using backtracking 


//Link :- https://www.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps3852/1

class Solution {
  private:
    // function to check if the cell is valid 
    bool isSafe(int row, int col, int &n, vector<vector<int>>& mat){
        if(row < 0 || col < 0 || row >= n || col >= n || mat[row][col] == 0)
            return false;
        
        return true;
    }
    
    // recursive function to find the path 
    bool findPath(int row, int col, vector<vector<int>>& mat, vector<vector<int>>& ans, int &n){
        // base case : if destination is reached 
        if(row == n-1 && col == n-1){
            ans[row][col] = 1;
            return true;
        }
        
        // check if cell is valid and not visited 
        if(isSafe(row, col, n, mat) && !ans[row][col]){
            // mark cell
            ans[row][col] = 1;
            
            // try moving right first 
            for(int jump=1; jump<=mat[row][col] && jump<n; ++jump){
                if(findPath(row, col+jump, mat, ans, n))
                    return true;
                
                if(findPath(row+jump, col, mat, ans, n))
                    return true;
            }
            // backtrack
            ans[row][col] = 0;
            return false;
        }
        return false;
    }
    
  public:
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();
        // initalize the path matrix 
        vector<vector<int>> ans(n, vector<int> (n, 0));
        
        // if no path exist then return -1
        if(!findPath(0, 0, mat, ans, n))
            return {{-1}};
        
        return ans;
    }
};