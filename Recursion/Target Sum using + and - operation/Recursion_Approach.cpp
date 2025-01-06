#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int res = 0, n, goal;

    void helper(int ind, int sum, vector<int> &nums){
        if(ind == n){
            if(sum == goal)
                res++;
            
            return;
        }
        helper(ind+1, sum + nums[ind], nums);
        helper(ind+1, sum + (-1*nums[ind]), nums);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size(), goal = target;
        helper(0, 0, nums);
        return res;
    }
};