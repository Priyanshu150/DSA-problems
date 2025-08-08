#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n)  
// Space complexity :- O(n*n)

// Approach :-
// As there are n-1 moves, child1 can only moves on principle diagonal 
// child2 & child3 can not cross the diagonal with the limited number of moves 
// we'll explore all the row & col for each child2 & child3 with the limited number of moves using dfs
// final answer will be the points collected by each student 


// Link :- https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/

class Solution {
    using ll = long long;
    static constexpr int INF = std::numeric_limits<int>::max();

    int dfs(const vector<vector<int>> &fruits, int row, int col, int moves, vector<vector<int>> &dp, const vector<pair<int,int>> &dirs){

        int n = fruits.size();
        if(row == n-1 && col == n-1)
            return moves == 0 ? 0 : INF;
        if(moves == 0 || row == col)
            return INF;
        if(dp[row][col] != -1)
            return dp[row][col];
        
        ll max_fruits = -1; 
        for(auto [drow, dcol]: dirs){
            int nrow = row + drow, ncol = col + dcol;
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
                int val = dfs(fruits, nrow, ncol, moves-1, dp, dirs);
                if(val != INF)
                    max_fruits = max(max_fruits, (ll)val);
            }
        }
        return dp[row][col] = (max_fruits < 0 ? INF : fruits[row][col] + max_fruits);
    }

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        ll first = 0;
        for(int i=0; i<n; ++i)
            first += fruits[i][i];
        
        vector<pair<int,int>> dir1 = {{1,-1}, {1,0}, {1,1}};
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int second = dfs(fruits, 0, n-1, n-1, dp, dir1);

        vector<pair<int,int>> dirs2 = {{-1,1}, {0,1}, {1,1}};
        for(auto &row: dp)      fill(begin(row), end(row), -1);
        int third = dfs(fruits, n-1, 0, n-1, dp, dirs2);

        return first + second + third;
    }
};