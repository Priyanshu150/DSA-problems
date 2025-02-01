#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O((n*m)^2)
// Space complexity :- O(1)

// Approach :-  
// Traverse in every cell of matrix try to first letter of string 
// If found call dfs to search rest of the word
// In dfs, expolore the adjacent option for cell matching with the next char
// if found go on to that cell and repeat the same
// If after trying all index you exhauted the string that means the word in present 
// After trying all case, if you didn't find the next char bracktrack and mark the cell as not visited and return false


//Link :- https://www.geeksforgeeks.org/problems/word-search/1

class Solution {
  private:
    int n, m, sz;
    vector<vector<bool>> vis;
    vector<int> dirs = {0, -1, 0, 1, 0};
    
    bool isValid(int row, int col){
        return (row>=0 && row<n && col>=0 && col<m);
    }
    
    bool dfs(int row, int col, int ind, vector<vector<char>>& mat, string& word){
        vis[row][col] = true;
        
        if(ind == sz)
            return true;
        
        for(int i=0; i<4; ++i){
            int nr = row+dirs[i], nc = col+dirs[i+1];
            if(isValid(nr, nc) && !vis[nr][nc] && mat[nr][nc] == word[ind]){
                if(dfs(nr, nc, ind+1, mat, word))
                    return true;
            }
        }
        vis[row][col] = false;
        return false;
    }
  
  public:
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        n = mat.size(), m = mat[0].size(), sz = word.size();
        vis.resize(n, vector<bool> (m, false));
        
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(word[0] == mat[row][col] && dfs(row, col, 1, mat, word))
                    return true;
            }
        }
        return false;
    }
};

