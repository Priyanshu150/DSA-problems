#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(2*N)       
//Space complexity :- O(1)    

class Solution {
    #define ll long long        // because of the high contraint (int) will not suffice
    
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), res = 0;
        ll rSum = 0, lSum = 0;
        rSum = accumulate(nums.begin(), nums.end(), rSum);

        for(int i=0; i<n-1; ++i){
            lSum += nums[i];
            rSum -= nums[i];
            if(lSum >= rSum)
                res++;
            
        }
        return res;
    }
};