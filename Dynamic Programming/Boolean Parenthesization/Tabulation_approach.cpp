#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n*n*2)
// Space complexity :- O(n*n*2)

// Approach :-  
// We can save the stack space on memoization problem, by applying tabulation
// Expressing the base case explicitily in the dp array
// i can be expressed from 0 to n-1, j can be expressed as i+1 to n and we can carry the isTrue as 0 & 1 directly 
// express all the possibilities as it is from the memoization case
// At last the answer will be stored at dp[0][n-1][1]


//Link :- https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1

class Solution {
    public:
      int countWays(string &s) {
          // code here
          int n = s.size();
          vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int> (2, 0)));
          
          for(int i=0; i<n; ++i){
              dp[i][i][1] = (s[i]=='T');
              dp[i][i][0] = (s[i]=='F');
          }
          
          for(int i=n-1; i>=0; --i){
              for(int j=0; j<n; ++j){
                  if(i>j || i==j)     continue;
                  
                  for(int ind=i+1; ind<=j-1; ind+=2){
                      int lt = dp[i][ind-1][1];
                      int lf = dp[i][ind-1][0];
                      int rt = dp[ind+1][j][1];
                      int rf = dp[ind+1][j][0];
                      
                      if(s[ind] == '&'){
                          dp[i][j][1] = dp[i][j][1] + (lt*rt);
                          dp[i][j][0] = dp[i][j][0] + (lt*rf) + (lf*rt) +(lf*rf);
                      }
                      else if(s[ind] == '|'){
                          dp[i][j][1] = dp[i][j][1] + (lt*rt) + (lf*rt) + (lt*rf);
                          dp[i][j][0] = dp[i][j][0] + (lf*rf);
                      }
                      else{
                          dp[i][j][1] = dp[i][j][1] + (lt*rf) + (lf*rt);
                          dp[i][j][0] = dp[i][j][0] + (lt*rt) + (lf*rf);
                      }
                  }
              }
          }
          return dp[0][n-1][1];
      }
  };


class Solution {
    public:
      int countWays(string &s) {
          // code here
          int n = s.size(); 
          vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, 0)));
          
          for(int i=0; i<n; i+=2){
              for(int isTrue=0; isTrue<=1; isTrue++){
                  if(isTrue)  dp[i][i][isTrue] = (s[i] == 'T');
                  else    dp[i][i][isTrue] = (s[i] == 'F');
              }
          }
          
          for(int i=n-1; i>=0; i--){
              for(int j=i+1; j<n; ++j){
                  for(int isTrue=0; isTrue<=1; isTrue++){
                      for(int ind=i+1; ind<j; ind+=2){
                          int lf = dp[i][ind-1][0];
                          int lt = dp[i][ind-1][1];
                          int rf = dp[ind+1][j][0];
                          int rt = dp[ind+1][j][1];
                          
                          if(s[ind] == '&'){
                              if(isTrue)   dp[i][j][isTrue] += (lt * rt);
                              else         dp[i][j][isTrue] += ((lf * rt) + (lt * rf) + (lf * rf));
                          }
                          else if(s[ind] == '|'){
                              if(isTrue)  dp[i][j][isTrue] += ((lf * rt) + (lt * rf) + (lt * rt));
                              else        dp[i][j][isTrue] += (lf * rf);
                          }
                          else{
                              if(isTrue)  dp[i][j][isTrue] += ((lf * rt) + (lt * rf));
                              else        dp[i][j][isTrue] += ((lf * rf) + (lt * rt));
                          }
                      }
                  }
              }
          }
          return dp[0][n-1][1];
      }
  };