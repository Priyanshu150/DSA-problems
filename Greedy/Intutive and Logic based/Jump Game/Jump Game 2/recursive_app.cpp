#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*n)
//Space complexity :- O(1) 

// Approach :-
// try out all the possibilities to jump from the current index 
// and pick the minimum jump from all, same ways used in jump game 1 

//link :- https://leetcode.com/problems/jump-game-ii/

class Solution {
private:
    int solve(int ind, int jumps, vector<int> &nums, int &n){
        // base case 
        if(ind >= n-1)
            return jumps;
        
        // jump can be taken from current index 
        int maxJump = nums[ind], res = INT_MAX;

        for(int i=1; i<=maxJump; ++i){
            // jump till index (ind+i) and try to reach end if possible 
            res = min(res, solve(ind+i, jumps+1, nums, n));
        }
        return res;
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        return solve(0, 0, nums, n);
    }
};