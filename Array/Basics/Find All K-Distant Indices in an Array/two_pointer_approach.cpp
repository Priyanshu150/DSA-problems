#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-
// maintain a pointer which points to the where nearest key index is present 

// Link :- https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/


class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size(), ind = 0;

        while(ind < n && nums[ind] != key)  
            ++ind;

        for(int i=0; i<n; ++i){
            if(ind != n && abs(ind - i) <= k)
                ans.push_back(i);
            else if(ind < i){
                ind += 1;
                while(ind < n && nums[ind] != key)  
                    ++ind;
                --i;
            }
        }
        return ans;
    }
};