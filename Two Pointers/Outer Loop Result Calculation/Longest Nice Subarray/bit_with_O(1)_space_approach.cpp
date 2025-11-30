#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(1)

// Approach :-  
// nums[i] can go till 1e9 which can be accomodated in 30 bits
// for finding every pair in subarray to have '&' value as 0, every bit in 30 bit should only be occupied once
// becuase if any two number have same bit it will give us some value instead of giving us 0
// this is based on the property of '&' operator i.e. 1&1 = 1 otherwise 0
// we'll use the sliding window technique to keep tack of all the window wheather it's valid or not

// Approach1 :- 
// for tracking the current present bit in subarray we'll use a variable 'val' and do an '|' operation that will set the bit 
// before adding the next element we'll check if the '&' with current_elment give 0 or not
// if not then we need to remove the element from left side of the subarray utill this becomes valid
// for removing the bits we use '^' operator to remove bit as xorr of same number gives 0
// after the subarray is valid we can do the or operation '|' 
// the window size will be (right - left + 1), we will keep track of max window size

// Approach2 :-
// if every num if set and unset bit then there is a property
// where sum of all the number will be equal to xorr of all the numbers
// so we'll find the sum and xorr of each number and form a subarray
// if we didn't got the sum == xorr, we'll remove the num from the left side of subbaray
// once the subarray becomes valid then, the window size will be (right - left + 1)
// also we will keep track of max window size which will be our ans

// Link :- https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

//Approach_1
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), val = 0, left = 0, res = 0;

        for(int right=0; right<n; ++right){
            while((val & nums[right]) != 0){
                val ^= nums[left];
                ++left;
            }
            val |= nums[right];
            res = max(res, right-left+1);
        }
        return res;
    }
};

//Approach_2
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, res = 0, n = nums.size();
        int xorValue = 0, currSum = 0;

        for(int right=0; right<n; ++right){
            xorValue ^= nums[right];
            currSum += nums[right];

            while(currSum != xorValue){
                xorValue ^= nums[left];
                currSum -= nums[left];
                ++left;
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};