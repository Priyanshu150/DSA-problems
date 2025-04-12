#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*m)                 
// Space complexity :- O(n*m)                  

// Approach :-
// We can use the concept of multisource bfs to calculated time 
// traverse the matrix and push all {row, col} having value as 2 in queue
// also count the number of ones in the matrix, if there are no ones the time taken will be 0
// Apply bfs traverse on the multiple nodes at the same time and push next level of nodes in queue
// while traversing in adjacent directions mark adjacent fresh oranges(1) to rotten oranges(2) to not traverse on it again
// repeat until queue becomes empty, calculate the time simultaneously for each level 
// time taken will be equal to level traverse for bfs - 1
// decrement the number of fresh orange while push it into queue 
// at last if the number of ones is greater than 0 then return -1 that it's not possible 


// Links :- https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

class Solution {
  private:
    #define pii pair<int,int>
    
    bool isValid(int row, int col, int &n, int &m){
        return (row>=0 && row<n && col>=0 && col<m);
    }
  
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size(), m = mat[0].size(), ones = 0, res = 0;
        queue<pii> q;
        int dir[] = {-1, 0, 1, 0, -1};
        
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(mat[row][col] == 2){
                    q.push({row, col});
                }
                else if(mat[row][col] == 1)
                    ones++;
            }
        }
        if(ones == 0)       return 0;
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz-- >0){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for(int i=0; i<4; ++i){
                    int nrow = row + dir[i], ncol = col + dir[i+1];
                    if(isValid(nrow, ncol, n, m) && mat[nrow][ncol] == 1){
                        q.push({nrow, ncol});
                        mat[nrow][ncol] = 2;
                        ones--;
                    }
                }
            }
            ++res;
        }
        if(ones != 0)   return -1;
        return res-1;
    }
};