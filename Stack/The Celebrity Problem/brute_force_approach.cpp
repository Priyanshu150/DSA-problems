#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*(n+m))
// Space complexity :- O(1)

// Approach :- 
// the person who is celebrity will have all the it's col value as 1 
// and row val as 0 apart from 1 value because celebrity know himself
// check for all the person to check the above conditions 

//Link :- https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        
        for(int person=0; person<n; ++person){
            int colCnt = 0, rowCnt = 0;
            
            for(int col=0; col<m; ++col){
                if(mat[person][col])
                    colCnt++;
            }
            for(int row=0; row<n; ++row){
                if(mat[row][person])
                    rowCnt++;
            }
            if(colCnt == 0 && rowCnt == n-1)
                return person;
        }
        return -1;
    }
};