#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(sz*n*m*len(str))
//Space complexity :- O(n*m)

// Approach :-  

// Link :- https://leetcode.com/problems/ones-and-zeroes/

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
        vector<vector<int>> ahead(m+1, vector<int> (n+1, 0)), curr = ahead;

        for(int ind=sz-1; ind>=0; --ind){
            for(int j=0; j<=m; ++j){
                for(int k=0; k<=n; ++k){
                    // try out notTake and take case 
                    curr[j][k] = ahead[j][k];
                    
                    // count the number of 1's & 0's in current string
                    pii cnt = findCount(strs[ind]);
                    int oneCnt = cnt.first, zeroCnt = cnt.second;

                    if(oneCnt <= k && zeroCnt <= j){
                        // return the maximum answer possible 
                        curr[j][k] = max(curr[j][k], 1+ahead[j - zeroCnt][k - oneCnt]);
                    }
                }
            }
            ahead = curr;
        }
        return ahead[m][n];
    }
};