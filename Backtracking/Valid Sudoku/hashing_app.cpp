#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(9^n * 81)
//Space complexity :- O(1)

// Approach :-  
// create a unique hash for every row, col and box and add them into the hash set 
// if any hash value repeat that means it's not valid 

// Link :- https://leetcode.com/problems/valid-sudoku/description/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> s;
        
        // traverse on each cell 
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    // create a unique hash
                    string row = "row"+to_string(i)+board[i][j];
                    string col = "col"+to_string(j)+board[i][j];
                    string box = "box"+to_string((i/3)*3+(j/3))+board[i][j];
                    
                    // check if hash exist or not 
                    if(s.find(row)==s.end() && s.find(col)==s.end() && s.find(box)==s.end()){
                        // add the hash value into has set 
                        s.insert(row);
                        s.insert(col);
                        s.insert(box);
                    }
                    else 
                        return false;       // already exist then return false 
                }
            }
        }
        return true;
    }
};