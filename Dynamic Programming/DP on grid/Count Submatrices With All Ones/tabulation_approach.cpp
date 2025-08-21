#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(m*m*n)
//Space complexity :- O(n)

// Approach :-   
// concept - finding count of matrix in 1-D array
// using the same concept we can convert the 2-D matrix into 1-D array 
// Trying all the combination of row using two for loops and then traversing on each columns 
// to create 1-D array using & operatins we will create it 
// if any column has 0 value that means whole row will have 0 value 
// accumulate all the answers of the 1D grid 


//link :- https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
private:
    int countWays(vector<int> arr, int size){
        int consOnes = 0, res = 0;

        for(int i=0; i<size; ++i){
            if(arr[i] == 1)
                consOnes++;
            else 
                consOnes = 0;
            
            res += consOnes;
        }   
        return res;
    }

public:
    int numSubmat(vector<vector<int>>& mat) {
        int res = 0, m = mat.size(), n = mat[0].size();

        for(int rowSt = 0; rowSt<m; rowSt++){
            vector<int> temp(n, 1);

            for(int rowEnd = rowSt; rowEnd<m; ++rowEnd){
                for(int col=0; col<n; ++col){
                    temp[col] &= mat[rowEnd][col];
                }
                res += countWays(temp, n);
            }
        }
        return res;
    }
};