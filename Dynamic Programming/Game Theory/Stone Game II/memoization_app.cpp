#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(n*n*2*n)
// Space complexity :- O(n*n*2)

// Approach :-  
// we'll try all ways to explore the ways and find the answers 
// there will be 3 changing states, person(0/1), ind(0 to n-1) and M(0 to n)
// for every state if the person is alice that is 0
// we'll add the stone sum value and sub-process will give us the remaining value and tryu to maximize the value 
// whenever we'll person == 1, then we'll try to minimize the value 
// this states can be memoized using 3d dp 

// Link :- https://leetcode.com/problems/stone-game-ii/description/


class Solution {
private:
    int solve(int person, int ind, int M, vector<int> &piles, int &n, vector<vector<vector<int>>> &dp){
        if(ind >= n)    return 0;
        if(dp[person][ind][M] != -1)
            return dp[person][ind][M];
        
        int stones = 0;
        int result = (person == 0) ? INT_MIN : INT_MAX;

        for(int x=1; x<=min(2*M, n-ind); ++x){
            stones += piles[ind];
            ++ind;
            // Alice's turn 
            if(person == 0){
                int val = stones + solve(1, ind, max(M, x), piles, n, dp);
                result = max(result, val);
            }else{      // Bob's turn   
                int val = solve(0, ind, max(M, x), piles, n, dp);
                result = min(result, val);
            }
        }
        return dp[person][ind][M] = result;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>> (n+1, vector<int> (n+1, -1)));
        return solve(0, 0, 1, piles, n, dp);
    }
};