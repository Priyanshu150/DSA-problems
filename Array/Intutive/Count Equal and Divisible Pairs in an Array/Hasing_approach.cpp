#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(n*n)    , for worst case 
// Space complexity :- O(n)

// Approach :-
// Store the all the index into a map, repective to the value 
// Traverse on the index later to find the index which satisfies the condition 


// Link :- https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<n; ++i){
            if(mp.count(nums[i])){
                for(auto ind: mp[nums[i]]){
                    if((ind*i)%k == 0)
                        res++;
                }
            }
            mp[nums[i]].push_back(i);
        }
        return res;
    }
};