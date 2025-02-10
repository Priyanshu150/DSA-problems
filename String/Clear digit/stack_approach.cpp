#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Use stack to solve the problem 
// Traverse the string by each char, if we got digit pop from the stack other push into the stack

// Link :- https://leetcode.com/problems/count-number-of-bad-pairs/

class Solution {
    #define ll long long 
public:
    long long countBadPairs(vector<int>& nums) {
        ll res = 0;
        int n = nums.size();
        unordered_map<int, ll> mp;

        for(int i=0; i<n; ++i){
            int new_pair = i, value = nums[i] - i;
            if(mp.count(value))
                new_pair -= mp[value];
            
            res += new_pair;
            mp[value] += 1;
        }
        return res;
    }
};