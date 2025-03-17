#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// We'll use map to store the element along with the number of times it occured
// Frequency of every element should be equal to even number otherwise it'll be not possible

// Link :- https://leetcode.com/problems/divide-array-into-equal-pairs/

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto num: nums)
            mp[num] += 1;
        
        for(auto [num, cnt]: mp){
            if(cnt%2 != 0)
                return false;
        }
        return true;
    }
};