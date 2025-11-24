#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*3)
// Space complexity :- O(3)


//Link :- https://leetcode.com/problems/greatest-sum-divisible-by-three/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        // initalize 2 dp of size 3 with min value 
        vector<int> prev(3, INT_MIN), curr = prev;
        // base case 
        prev[0] = 0;

        for(int ind=1; ind<=n; ++ind){
            for(int rem=0; rem<3; ++rem){
                // explore all possibilities
                int notTake = prev[rem];
                int take = nums[ind-1] + prev[(rem + nums[ind-1])%3];
                // take max of both possibilities
                curr[rem] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[0];
    }
};