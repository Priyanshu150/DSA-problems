#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)                  // Where n is size of array 
// Space complexity :- O(n)                  // n is space for dp arrays

// Approach :-
// to reduce the stack space we can use tabulation approach 
// express the base case first mark all the values of dp array as 0, since there will be 0 score initially 
// ind will go from n-1 to 0, express the same possibilities of memozation under the loop 
// our answer will be present at dp[0]


// Links :- https://leetcode.com/problems/solving-questions-with-brainpower/

class Solution {
private:
    #define ll long long

public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n+1, 0);

        for(int ind=n-1; ind>=0; --ind){
            int points = questions[ind][0];
            int jumps = questions[ind][1];
            int nextQ = min(n, ind+jumps+1);

            dp[ind] = max(dp[ind+1], points+dp[nextQ]);
        }
        return dp[0];
    }
};