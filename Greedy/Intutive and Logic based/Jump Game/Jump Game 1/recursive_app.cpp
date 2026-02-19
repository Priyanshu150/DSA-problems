#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*n)
//Space complexity :- O(1) 

// Approach :-
// try out all way to jump from current index and explore all possibilities using recursion 
// somehow we're able to reach end then it's possible otherwise it's not 
// the time complexity will be exponential and hence we can memoize the solution using dp 

//link :- https://leetcode.com/problems/jump-game/description/

class Solution {
private:
    bool solve(int ind, vector<int> &nums, int &n){
        // base case 
        if(ind >= n-1)
            return true;
        
        // jump can be taken from current index 
        int jump = nums[ind];       

        for(int i=1; i<=jump; ++i){
            // jump till index (ind+i) and try to reach end if possible 
            if(solve(ind+i, nums, n)){
                return true;
            }
        }
        return false;
    }

public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // try out all ways using recursion 
        return solve(0, nums, n);
    }
};