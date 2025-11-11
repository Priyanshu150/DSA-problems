#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(sz*n*m*len(str))
//Space complexity :- O(sz*n*m)


// Link :- https://leetcode.com/problems/ones-and-zeroes/

// code 1 :- 

class Solution {
private:
    typedef pair<int,int> pii;

    pii findCount(string &str){
        int ones = 0, zeros = 0;

        for(auto ch: str){
            // count 1's and 0's
            if(ch == '1')       ones++;
            else                zeros++;
        }
        return {ones, zeros};
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>> dp(sz+2, vector<vector<int>> (m+2, vector<int> (n+2, 0)));

        for(int ind=sz-1; ind>=0; --ind){
            for(int j=0; j<=m; ++j){
                for(int k=0; k<=n; ++k){
                    int &ans = dp[ind][j][k];

                    // try out notTake and take case 
                    ans = dp[ind+1][j][k];
                    
                    // count the number of 1's & 0's in current string
                    pii cnt = findCount(strs[ind]);
                    int oneCnt = cnt.first, zeroCnt = cnt.second;

                    if(oneCnt <= k && zeroCnt <= j){
                        // return the maximum answer possible 
                        ans = max(ans, 1 + dp[ind+1][j - zeroCnt][k - oneCnt]);
                    }
                }
            }
        }
        return dp[0][m][n];
    }
};

// code 2 :- 

class Solution {
private:
    typedef pair<int,int> pii;

    pii findCount(string &str){
        int ones = 0, zeros = 0;

        for(auto ch: str){
            // count 1's and 0's
            if(ch == '1')       ones++;
            else                zeros++;
        }
        return {ones, zeros};
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        int dp[602][102][102];

        // intializing dp value to 0
        memset(dp, 0, sizeof(dp));

        for(int ind=sz-1; ind>=0; --ind){
            for(int j=0; j<=m; ++j){
                for(int k=0; k<=n; ++k){
                    int &ans = dp[ind][j][k];

                    // try out notTake and take case 
                    ans = dp[ind+1][j][k];
                    
                    // count the number of 1's & 0's in current string
                    pii cnt = findCount(strs[ind]);
                    int oneCnt = cnt.first, zeroCnt = cnt.second;

                    if(oneCnt <= k && zeroCnt <= j){
                        // return the maximum answer possible 
                        ans = max(ans, 1 + dp[ind+1][j - zeroCnt][k - oneCnt]);
                    }
                }
            }
        }
        return dp[0][m][n];
    }
};