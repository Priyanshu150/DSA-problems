#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Traverse through the array find the number of digit of that number
// If that number is present in map caluculate the sum and update the max value of that digit in map
// If not present put it into the map toward the digit value of that number

// Link :- https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

class Solution {
    private:
    int countOfDigits(int num){
        int res = 0;

        while(num > 0){
            int ld = num % 10;
            num /= 10;
            res += ld;
        }
        return res;
    }

public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size(), res = -1;
        unordered_map<int,int> mp;

        for(int i=0; i<n; ++i){
            int digitCnt = countOfDigits(nums[i]);
            if(mp.count(digitCnt)){
                res = max(res, mp[digitCnt] + nums[i]);
                if(nums[i] > mp[digitCnt])
                    mp[digitCnt] = nums[i];
            }
            else    mp[digitCnt] = nums[i];
        }
        return res;
    }
};