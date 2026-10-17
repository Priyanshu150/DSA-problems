#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*m)  where n is number of rows and m is number of columns
// Space Complexity: O(n*m)  

// Approach : 
// 1. We will use Kahn's algorithm to find the longest increasing path in the matrix.
// 2. We will first calculate the in-degree of each cell in the matrix.
// 3. We will then add all the cells with in-degree 0 to a queue and perform a topological sort on the graph.
// 4. We will keep track of the number of levels in the topological sort, 
//      which will give us the length of the longest increasing path in the matrix.
// 5. We will return the length of the longest increasing path as the final answer.

// Link :- https://www.geeksforgeeks.org/problems/longest-increasing-path-in-a-matrix/1

class Solution {
  private:
    bool isValid(int row, int col, int &n, int &m, vector<vector<int>> &matrix, int prevVal){
        return (row >= 0 && row < n && col >= 0 && col < m && matrix[row][col] > prevVal);
    }
  
  public:
    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        int dirs[5] = {-1, 0, 1, 0, -1};
        
        vector<vector<int>> inDegree(n, vector<int> (m, 0));
        
        // traverse on all cells of matrix considering it as a node 
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                // traverse on adjacent cells 
                for(int i=0; i<4; ++i){
                    int nrow = row + dirs[i];
                    int ncol = col + dirs[i+1];
                    
                    // check if cell is valid for traversal 
                    if(isValid(nrow, ncol, n, m, matrix, matrix[row][col])){
                        // count the number of inDegree 
                        inDegree[nrow][ncol] += 1;
                    }
                }
            }
        }
        
        queue<pair<int,int>> q;
        
        // add the row which has 0 indegree 
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(inDegree[row][col] == 0){
                    q.push({row, col});
                }
            }
        }
        
        int res = 0;
        
        // apply khan's algorithm 
        while(!q.empty()){
            int sz = q.size();
            
            while(sz-- > 0){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                 // traverse on adjacent cells 
                for(int i=0; i<4; ++i){
                    int nrow = row + dirs[i];
                    int ncol = col + dirs[i+1];
                    
                    // check if cell is valid for traversal 
                    if(isValid(nrow, ncol, n, m, matrix, matrix[row][col])){
                        // relax the edge 
                        inDegree[nrow][ncol] -= 1;
                        
                        if(inDegree[nrow][ncol] == 0)
                            q.push({nrow, ncol});
                    }
                }
            }
            ++res;
        }
        return res;
    }
};