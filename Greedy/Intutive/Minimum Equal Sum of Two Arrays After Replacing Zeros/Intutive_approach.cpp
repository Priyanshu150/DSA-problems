#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(1)

// Approach :- 
// find the sum of the both the array considering the 0 as 1 replacing with the least number 
// if both the sum is equal then return the sum and we're sorted
// if sum1 is greater that sum2 then if any zeros are present in arr2 
// then it's possible to have equal sum otherwise not and vice versa 
// at last return -1, denotring it's not possible


// Link :- https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        bool flag1 = false, flag2 = false;
        
        for(auto it: nums1){
            if(it==0){
                sum1 += 1;
                flag1 = true;
            }
            else
                sum1 += it;
        }
        
        for(auto it: nums2){
            if(it==0){
                sum2 += 1;
                flag2 = true;
            }
            else
                sum2 += it;
        }
        if(sum1 == sum2)
            return sum1;
        
        if(sum1 > sum2 && flag2)
            return sum1;
        
        if(sum2 > sum1 && flag1)
            return sum2;
        
        return -1;
    }
};