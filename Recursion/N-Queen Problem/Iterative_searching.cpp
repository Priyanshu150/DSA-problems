#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n!*n)
// Space complexity :- O(n)

// Approach :- 
// Try all possible way to put the queens 
// f(column, sequence) => The state of recurion will be column and sequence which stores queens kept at every row
// At every recurion stage, we'll try keeping a queen at partiuclar row
// We'll check iteratively that a queen is present in the same row, upper diagonal or lower diagonal
// If not then we'll keep it there and call recursion to execute the furture
// Once every col is filled we will reach at n, the we can store our sequence in ans and return

//Link :- https://www.geeksforgeeks.org/problems/n-queen-problem0315/1

class Solution {
  private:
    vector<vector<int>> ans, board;
    
    bool isSafe(int row, int col, int &n){
        int dupRow = row, dupCol = col;
        
        while(row >= 0 && col >= 0){
            if(board[row][col] == 1)
                return false;
            
            row--; col--;
        }
        row = dupRow, col = dupCol;
        
        while(col>=0){
            if(board[row][col] == 1)
                return false;
            
            col--;
        }
        col = dupCol;
        
        while(row<n && col>=0){
            if(board[row][col] == 1)
                return false;
            
            row++; col--;
        }
        return true;
    }
    
    void solve(int col, int &n, vector<int> seq){
        if(col == n){
            ans.push_back(seq);
            return;
        }
        for(int row=0; row<n; ++row){
            if(isSafe(row, col, n)){
                board[row][col] = 1;
                seq.push_back(row+1);
                solve(col+1, n, seq);
                seq.pop_back();
                board[row][col] = 0;
            }
        }
    }
  
  public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<int> seq;
        board.resize(n, vector<int> (n, 0));
        solve(0, n, seq);
        return ans;
    }
};