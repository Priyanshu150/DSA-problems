#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// First find the strictly increasing sub-array and then stricly decreasing sub-array
// find which one have larger length
// For find either of them traverse the array and keep track of the length depending on the previous number occured

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), res = 0;
        int len = 0, prevInc = -1;
        int len1 = 0, prevDec = 55;

        for(int i=0; i<n; ++i){
            if(prevInc < nums[i])       len++;
            else        len = 1;

            if(prevDec > nums[i])     len1++;
            else        len1 = 1;

            prevInc = nums[i];
            prevDec = nums[i];
            res = max({res, len, len1});
        }
        return res;
    }
};

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), len = 0, lis = 0, lds = 0, prev = -1;

        for(int i=0; i<n; ++i){
            if(prev < nums[i])
                len++;
            else{
                lis = max(lis, len);
                len = 1;
            }
            prev = nums[i];
        }
        lis = max(lis, len);
        prev = 55, len = 0;

        for(int i=0; i<n; ++i){
            if(prev > nums[i])     len++;
            else        len = 1;
            lds = max(lds, len);
            prev = nums[i];
        }
        return max(lds, lis);
    }
};