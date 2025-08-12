#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m*x)
// Space complexity :- O(n*m)

// Approach :- 
// In tabulation we'll convert, diceCnt from n-1 to 0 and sum from 1 to x
// expressing the same possibilites as memoization 
// we'll get our answer stored at dp[0][x]

// Link :- https://www.geeksforgeeks.org/problems/dice-throw5349/1

class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>> dp(n+1, vector<int> (x+1, 0));
        
        dp[n][0] = 1;
        
        for(int diceCnt=n-1; diceCnt>=0; --diceCnt){
            for(int sum=1; sum<=x; ++sum){
                for(int faceVal=1; faceVal<=m; ++faceVal){
                    if(sum - faceVal >= 0){
                        dp[diceCnt][sum] += dp[diceCnt+1][sum - faceVal];
                    }
                }
            }
        }
        return dp[0][x];
    }
};