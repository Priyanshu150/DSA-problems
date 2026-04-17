#include <bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*len(d))
// Space complexity :- O(1)

// Approach :- 
// store the reverse digit of every number 
// check whether the current number's reverse number is present or not 


// Links :- https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/

class Solution {
private:
    int reverse(int num){
        int res = 0;

        while(num > 0){
            int ld = num % 10;
            res = (res*10) + ld;
            num /= 10;
        }
        return res;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size(), res = INT_MAX;

        for(int i=0; i<n; ++i){
            if(mp.count(nums[i])){
                res = min(res, i - mp[nums[i]]);
            }
            int revNum = reverse(nums[i]);
            mp[revNum] = i;
        }
        return (res == INT_MAX) ? -1 : res;
    }
};