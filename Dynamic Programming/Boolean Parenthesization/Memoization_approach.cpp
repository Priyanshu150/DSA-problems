#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n*n*2)
// Space complexity :- O(n*n*2 + stack_space)

// Approach :-  
// Brackets can be applied at every possible possition to check wheather that is giving us a valid configuration or not 
// if yes then count them as a way, for trying all possibilites we can use recursion
// dp on block can be applied, start with 0 to n-1 as a whole block, which can be expressed as i & j be indexing
// Number appears every alternative index same as operator 
// so we can apply loop to from each block from i to j, let ind be our loop variable
// traversing on symbol, ind=i+1 to ind<j and the subproblem will be f(i, ind-1) & f(ind+1, j)
// if the operation is '|' then we've to find the number of ways to find true on right and true on left
// also number of ways to make false on left eqn and number of ways to make false on right 
// Even though question is asking us to make the true ways but we have to get false also to get total ways
// we can carry extra variable as parameter 'isTrue' can change it to 1 when needed for true otherwise 0
// The way we express for '|' same way we can express for '&' and '^'
// the base can be express as when i > j then return 0 as there will be no ways
// if (i == j), then if we're looking for true and s[i] == 'T' then 1 ways exist return the same
// otherwise looking for false then return other 1 way if s[i] == 'F' and call the function as f(0, n-1, 1)


//Link :- https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1


class Solution {
    private:
      int solve(int i, int j, int isTrue, string &s, vector<vector<vector<int>>> &dp){
          if(i > j)   return 0;
          if(i == j){
              if(isTrue)  return s[i] == 'T';
              return s[i] == 'F';
          }
          if(dp[i][j][isTrue] != -1) 
              return dp[i][j][isTrue];
          
          int ways = 0;
          
          for(int ind=i+1; ind<j; ind+=2){
              int lf = solve(i, ind-1, 0, s, dp);
              int lt = solve(i, ind-1, 1, s, dp);
              int rf = solve(ind+1, j, 0, s, dp);
              int rt = solve(ind+1, j, 1, s, dp);
              
              if(s[ind] == '&'){
                  if(isTrue)   ways += (lt * rt);
                  else         ways += ((lf * rt) + (lt * rf) + (lf * rf));
              }
              else if(s[ind] == '|'){
                  if(isTrue)      ways += ((lf * rt) + (lt * rf) + (lt * rt));
                  else            ways += (lf * rf);
              }
              else{
                  if(isTrue)      ways += ((lf * rt) + (lt * rf));
                  else            ways += ((lf * rf) + (lt * rt));
              }
          }
          return dp[i][j][isTrue] = ways;
      }
    
    public:
      int countWays(string &s) {
          // code here
          int n = s.size(); 
          vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, -1)));
          return solve(0, n-1, 1, s, dp);
      }
  };