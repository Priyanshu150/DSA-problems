#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(9^n * 81)
//Space complexity :- O(1)

// Approach :-  
// using sudoku solve technique, check that every cell filled is valid or not 


// Link :- https://leetcode.com/problems/valid-sudoku/description/

class Solution {
private:
    bool isValid(char ch, int row, int col, vector<vector<char>>& board){
        for(int i=0; i<9; ++i){
            if(board[i][col] == ch)
                return false;
            
            if(board[row][i] == ch)
                return false;
            
            if(board[(row/3)*3 + i/3][(col/3)*3 + i%3] == ch)
                return false;
        }
        return true;
    }


public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j] == '.')
                    continue;
                
                char ch = board[i][j];
                board[i][j] = '.';

                if(!isValid(ch, i, j, board))
                    return false;
                
                board[i][j] = ch;
            }
        }
        return true;
    }
};
