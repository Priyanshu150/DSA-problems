#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m*x)
// Space complexity :- O(n*m*stack_size)

// Approach :- 
// using the conecpt of subset sum
// find the sum of n dice using recusion
// diceCnt & ind will be our changing parameter
// we'll try to take all faceValue if it's greater or equal than 0
// count all the possible ways and the base cases will be when we complete the diceCnt to n 
// and the sum value is 0 then return 1 stating it's a possible sequence 

// Link :- https://www.geeksforgeeks.org/problems/dice-throw5349/1

class Solution {
  private:
    int solve(int diceCnt, int sum, int &m, int &n){
        if(diceCnt == n){
            return (sum == 0);
        }
        if(sum == 0)    return 0;
        
        int res = 0;
        for(int faceVal=1; faceVal<=m; ++faceVal){
            if(sum - faceVal >= 0){
                res += solve(diceCnt+1, sum - faceVal, m, n);
            }
        }
        return res;
    }
  
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        return solve(0, x, m, n);
    }
};