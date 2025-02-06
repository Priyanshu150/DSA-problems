#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Calculate the product of each pair in the array
// And count the freq of each product
// For each product if it's greater than 2 
// then the number of result will sum of (freq-1) i.e n natural numbers

// Link :- https://leetcode.com/problems/tuple-with-same-product/description/

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(), res = 0;
        unordered_map<int,int> mp;

        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                int prod = nums[i]*nums[j];
                mp[prod] += 1;
            }
        }
        for(auto [num, cnt]: mp)
            res += (cnt*(cnt-1))/2;

        return res*8;
    }
};