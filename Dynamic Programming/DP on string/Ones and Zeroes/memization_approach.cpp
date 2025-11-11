#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(sz*n*m*len(str))
//Space complexity :- O(sz*n*m + aux_stack)

// Approach :-  
// try all possible case using recusion, explore notTake and take case 
// for every string calculate the number of 1's and 0's using for loop 
// count the maximum number of sequence by doing that 
// memoize the dp using 3-d dp 

// Link :- https://leetcode.com/problems/ones-and-zeroes/

class Solution {
private:
    typedef pair<int,int> pii;

    int sz;
    int dp[602][102][102];

    pii findCount(string &str){
        int ones = 0, zeros = 0;

        for(auto ch: str){
            // count 1's and 0's
            if(ch == '1')       ones++;
            else                zeros++;
        }
        return {ones, zeros};
    }

    int solve(int ind, int m, int n, vector<string>& strs){
        // base case 
        if(ind == sz)
            return 0;

        int &ans = dp[ind][m][n];
        if(ans != -1)
            return ans;
        
        // try out notTake and take case 
        int notTake = solve(ind+1, m, n, strs), take = 0;
        
        // count the number of 1's & 0's in current string
        pii cnt = findCount(strs[ind]);
        int oneCnt = cnt.first, zeroCnt = cnt.second;

        if(oneCnt <= n && zeroCnt <= m){
            take = 1 + solve(ind+1, m - zeroCnt, n - oneCnt, strs);
        }
        // return the maximum answer possible 
        return ans = max(notTake, take);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        sz = strs.size();
        // intializing dp value to -1
        memset(dp, -1, sizeof(dp));
        return solve(0, m, n, strs);
    }
};