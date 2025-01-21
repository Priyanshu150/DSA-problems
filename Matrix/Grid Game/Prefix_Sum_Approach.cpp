#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(1)

//Approach :- 
// Robot1 can take different combination of path i.e (0 - i) in grid[0] & (i+1 - n) in grid[1]
// The path taken by Robot1 will leave 0 points in the cells 
// Robot2 has the option to take top_sum from (i+1 - n) in grid[0] or bottom_sum from (0 - i) in grid[1]
// It will choose the maximum sum out of both in every iteration
// Robot1 will minimize the sum choosen by robot2

//Link :- https://leetcode.com/problems/grid-game/

class Solution {
    #define ll long long 

public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if(n < 2)   return 0;

        ll top_sum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        ll bottom_sum = 0, min_sum = LONG_MAX;

        for(int pp=0; pp<n; ++pp){
            top_sum -= grid[0][pp];
            min_sum = min(min_sum, max(top_sum, bottom_sum));
            bottom_sum += grid[1][pp];
        }
        return min_sum;
    }
};