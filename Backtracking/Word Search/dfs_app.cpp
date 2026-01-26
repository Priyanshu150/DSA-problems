#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n × m × 4^sz)
// Space complexity :- O(n x m + sz)

// Approach :-  
// traverse of each cell of the matrix and find the first char of the word 
// for finding the rest of words traverse on grid 
// and use dfs to find the other letter of words
// use visited array to keep track of cell already tracked 
// backtracts to the previous state in order to use same visited grid

// link :- https://www.geeksforgeeks.org/problems/word-search/1

class Solution {
  private:
    int n, m, sz;
    int dirs[5] = {-1, 0, 1, 0, -1};
    
    bool isValid(int row, int col){
        // validate if current cell is valid or not 
        return (row>=0 && row<n && col>=0 && col<m);
    }
  
    bool dfs(int row, int col, int ind, vector<vector<char>> &mat, string &word,
        vector<vector<bool>> &vis){
            
        // base case when we found the all char of string 
        if(ind == sz){
            return true;
        }
        // mark current cell as visited 
        vis[row][col] = true;
        
        // traverse on the adjacent cell of the curr cell 
        for(int i=0; i<4; ++i){
            int nrow = row + dirs[i];
            int ncol = col + dirs[i+1];
            
            // check if the adjacent cell's value is equal to next char of string
            if(isValid(nrow, ncol) && !vis[nrow][ncol] && mat[nrow][ncol] == word[ind]){
                // explore the further possibilities 
                if(dfs(nrow, ncol, ind+1, mat, word, vis))
                    return true;
            }
        }
        // backtract to the previous value 
        vis[row][col] = false;
        
        return false;
    }
  
  public:
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        n = mat.size();
        m = mat[0].size();
        sz = word.size();
        
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        // traverse on each cell of the matrix 
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                // check if cell value is equal to first value of word 
                if(mat[row][col] == word[0]){
                    if(dfs(row, col, 1, mat, word, vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};