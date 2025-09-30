#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n)  
// Space complexity :- O(n*n)

// Approach :- 
// find the sum of each row and each col. Among them find the max_sum
// now we have to make every row and col sum equal to max_sum
// count the value of each row or col sum minus max_sum
// divide that number by 2 that will be our answer
// why because it's always possible to make matrix beautiful


// Link :- https://www.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1

class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n){
        // code here 
        int maxSum = 0, diff = 0;
        vector<int> sums(n, 0);
        
        for(int i=0; i<n; ++i){
            int rowSum = 0;
            for(int j=0; j<n; ++j){
                rowSum += matrix[i][j];
                sums[j] += matrix[i][j];
                maxSum = max(maxSum, sums[j]);
            }
            maxSum = max(maxSum, rowSum);
            sums.push_back(rowSum);
        }
        
        for(auto it: sums){
            diff += (maxSum-it);
        }
        
        return diff/2;
    } 
};