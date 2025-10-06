#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(8^n)
//Space complexity :- O(8^n)

// Approach :-  
// Use backtracking and recusion to evaluate all the valid paths 
// start from (0,0) and explore all the possibilites 
// until unless one of them leaves us to the end of the moves i.e. n*n
// use boolean return type to keep track of the path which moves to the last and return true 


// Link :- https://www.geeksforgeeks.org/problems/the-knights-tour-problem/1

class Solution {
  private:
    vector<vector<int>> dirs = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    
    bool solve(int row, int col, int moves, int n, vector<vector<int>> &board){
        if(moves == n*n)
            return true;
        
        for(auto &dir: dirs){
            int nrow = row + dir[0];
            int ncol = col + dir[1];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && board[nrow][ncol] == -1){
                board[nrow][ncol] = moves;
                
                if(solve(nrow, ncol, moves+1, n, board))
                    return true;
                    
                board[nrow][ncol] = -1;
            }
        }
        return false;
    }
    
  public:
    vector<vector<int>> knightTour(int n) {
        // code here
        vector<vector<int>> board(n, vector<int> (n, -1));
        board[0][0] = 0;
        if(solve(0, 0, 1, n, board))
            return board;
        
        return {};
    }
};