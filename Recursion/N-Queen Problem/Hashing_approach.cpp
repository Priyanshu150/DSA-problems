#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n!)
// Space complexity :- O(n)

// Approach :- 
// Try all possible way to put the queens 
// f(column, sequence) => The state of recurion will be column and sequence which stores queens kept at every row
// At every recurion stage, we'll try keeping a queen at partiuclar row
// We'll use hashing to check that a queen is present in the same row, upper diagonal or lower diagonal
// If not then we'll keep it there and call recursion to execute the furture
// Once every col is filled we will reach at n, the we can store our sequence in ans and return

// For row, use (n) as a length and mark rowNo as true which mean a queen is already kept there 
// For lower_diagonal, use (2*n) as length and mark (row+col) as true which mean a queen is already kept there
// For upper_daigonal, use (2*n) as length and mark (n-1-row+col) as true which mean a queen is already kept there

//Link :- https://www.geeksforgeeks.org/problems/n-queen-problem0315/1

class Solution {
  private:
    vector<vector<int>> ans;
    vector<bool> rows_check, upper_diagonal, lower_diagonal;
    
    bool isSafe(int row, int col, int &n){
        return (!rows_check[row] && !lower_diagonal[row+col] && !upper_diagonal[n-1-row+col]);
    }
    
    void solve(int col, int &n, vector<int> seq){
        if(col == n){
            ans.push_back(seq);
            return;
        }
        for(int row=0; row<n; ++row){
            if(isSafe(row, col, n)){
                rows_check[row] = true;
                lower_diagonal[row+col] = true;
                upper_diagonal[n-1-row+col] = true;
                
                seq.push_back(row+1);
                solve(col+1, n, seq);
                seq.pop_back();
                
                rows_check[row] = false;
                lower_diagonal[row+col] = false;
                upper_diagonal[n-1-row+col] = false;
            }
        }
    }
  
  public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<int> seq;
        rows_check.resize(n, false);
        upper_diagonal.resize(n+n, false);
        lower_diagonal.resize(2*n, false);
        solve(0, n, seq);
        return ans;
    }
};