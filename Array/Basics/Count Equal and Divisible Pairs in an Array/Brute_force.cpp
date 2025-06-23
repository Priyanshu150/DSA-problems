#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n)
// Space complexity :- O(1)

// Approach :-
// Try looping twice for finding all the pairs and caluclate the result 

// Link :- https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;

        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(nums[i] == nums[j] && (i*j)%k == 0)
                    res += 1;
            }
        }
        return res;
    }
};