#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))  
// Space complexity :- O(n)

// Approach :-  
// the sequence of the number doesn't matter, the min and max number matters in that sequence
// [3,5,6] or [5,6,3] or [6,3,5] and so on will all be valid 
// hence we can sort the array 
// using two sum approach we'll start on the extreme end and find the pair sum 
// if the pair sum is greater than target we'll decrease the right pointer to decrease the pair sum
// otherwise we can count the valid sequence and increament the left ptr
// for seq cnt, count the total lenght of the valid sub-sequence
// apart from first element we've choice to either include every one or not 
// first number will be there because it's the smallest number 
// so the seq cnt will be 2^(len-1)
// precomute the power array as this will be cost operation while traversing


// Link :- https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

//approach1 
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), mod = 1e9+7;
        vector<int> power(n, 1);

        for(int i=1; i<n; ++i)
            power[i] = (power[i-1]*2)%mod;
        
        int left = 0, right = n-1, res = 0;

        while(left <= right){
            if(nums[left] + nums[right] > target)
                right--;
            else{
                res = (res + power[right - left]) % mod;
                ++left;
            }
        }
        return res;
    }
};

//approach2
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int res=0, mod=1e9+7, l=0, r=nums.size()-1;

        vector<int> pre = {1};
        for(int i=1; i<=r; ++i)
            pre.push_back((pre.back() << 1)%mod);
        
        sort(begin(nums), end(nums));

        while(l<=r){
            if(nums[l]+nums[r] > target)
                r--;
            else
                res = (res+pre[r-l++])%mod;
        }

        return res;
    }
};