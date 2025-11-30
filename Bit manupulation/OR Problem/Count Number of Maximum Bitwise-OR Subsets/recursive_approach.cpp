#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n) + n*log(max_diif))  
// Space complexity :- O(n)

// Approach :- 
// For find the maximum or we can take the 'or' because or of any two number only increases or stay same
// we can use recursion to find the sub-sequence count which has the 'or' value equal to max_or


// Link :- https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

class Solution {
private:
    int n, res=0, maxOrr = 0;

    void helper(int ind, int orr, vector<int> &nums){
        if(ind == n){
            if(maxOrr == orr)     res++;
            return;
        }
        helper(ind+1, orr | nums[ind], nums);
        helper(ind+1, orr, nums);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();

        for(int i=0; i<n; ++i)
            maxOrr |= nums[i];
        
        helper(0, 0, nums);
        return res;
    }
};
