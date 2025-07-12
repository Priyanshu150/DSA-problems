#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2^(n*n))
// Space complexity :- O(stack_space)

// Approach :-  
// try checking all possible path to find the maximum gold, use recursion for the same 
// start with every row in the first col 
// for every (row, col), try exploring right, upper diagonal and lower diagonal of the path 
// the base case will be when col reaches end i.e. mat[0].size() return 0 denoting no gold can be collected
// collect the maximum value of all the three paths 

// links :- https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1

class Solution {
  private:
    int n, m;
    
    int solve(int row, int col, vector<vector<int>>& mat){
        if(col == m)
            return 0;
        
        int up = 0, right = 0, down = 0;
        
        if(row-1 >= 0)
            up += solve(row-1, col+1, mat);
        
        if(row+1 < n)
            down += solve(row+1, col+1, mat);
        
        right = solve(row, col+1, mat);
        
        return mat[row][col] + max({up, right, down});
    }
    
  public:
    int maxGold(vector<vector<int>>& mat) {
        // code here
        n = mat.size();
        m = mat[0].size();
        int res = 0;
        
        for(int row=0; row<n; ++row){
            res = max(res, solve(row, 0, mat));
        }
        return res;
    }
};