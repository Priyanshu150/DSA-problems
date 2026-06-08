#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*m)
// Space complexity :- O(1)

// Approach :- 
// try keeping one of the knight in all the valid position 
// from that position cancel out all the once where it can reach in one move 
// If we place second knight on other squares it will be a valid combination 
// hence count all such ways to place the knigths 

// Link :- https://www.geeksforgeeks.org/problems/black-and-white-1587115620/1

class Solution {
  private:
    bool isValid(int row, int col, int &n, int &m){
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
    
  public:
    int numOfWays(int n, int m) {
        // all valid night moves 
        vector<pair<int,int>> knightMoves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                                            {1,-2}, {1,2}, {2,-1}, {2,1} };
        
        int totalSpaces = n*m;      // total space available in boards 
        int totalMoves = 0;         // total moves possible 
        
        // place one night on every row and column 
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                int oneKnightMove = 1;
                
                for(auto dir: knightMoves){
                    int nrow = row + dir.first;
                    int ncol = col + dir.second;
                    // find all the valid direction where the current night can move in one step 
                    if(isValid(nrow, ncol, n, m)){
                        // count all sum moves 
                        oneKnightMove += 1;
                    }
                }
                // place the other knight where the first night can not reach 
                totalMoves += (totalSpaces - oneKnightMove);
            }
        }
        return totalMoves;
    }
};
