#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(N)

// Approach :- 
// To get maximum sum of distinct element we'll take only positive distinct element 
// to keep track of a number already been taken or not we can hash their values 
// If we only have negative or zero in array for that case we'll delete everything except maximum value

// Link :- https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0, maxi = INT_MIN;
        unordered_set<int> st;

        for(auto num: nums){
            if(num > 0 && !st.count(num)){
                sum += num;
                st.insert(num);
            }
            maxi = max(maxi, num);
        }
        return sum == 0 ? maxi : sum;
    }
};