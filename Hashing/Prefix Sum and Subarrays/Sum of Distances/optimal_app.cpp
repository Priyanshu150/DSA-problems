#include <bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*log(n))
// Space complexity :- O(n)

// Approach :- 
// if there ind1, ind2, i, ind3, ind4 for a particular element then the formual will be 
// (i - ind1) + (i - ind2) + (ind3 - i) + (ind4 - i) when abs is removed 
// (ind4 + ind3)+0-(ind1 + ind2) mean sum of index on right side - sum of index on left side and 
//  freq of element of left side * i + freq on element on right * i
// using hash map we can store the required information of the same and use it optimally 

// Links :- https://leetcode.com/problems/sum-of-distances/

class Solution {
private:
    typedef long long ll;

public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<ll, ll> leftSum, rightSum;
        unordered_map<ll, ll> leftFreq, rightFreq;

        // pre-calculate the sum and freq of the elements 
        for(int i=0; i<n; ++i){
            rightSum[nums[i]] += i;
            rightFreq[nums[i]] += 1;
        }
        vector<ll> ans;

        for(int i=0; i<n; ++i){
            // update the right presum array
            rightSum[nums[i]] -= i;
            rightFreq[nums[i]] -= 1;
            
            // formula will be sum of index on right - sum of index on left side + count of number on left side * i - i* count of number on right side 
            ll sum = rightSum[nums[i]] - leftSum[nums[i]] + (i*leftFreq[nums[i]]) - (i*rightFreq[nums[i]]);
            ans.push_back(sum);

            // update the left presum array 
            leftSum[nums[i]] += i;
            leftFreq[nums[i]] += 1;
        }
        return ans;
    }
};