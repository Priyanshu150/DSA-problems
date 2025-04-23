#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// calculate the xor of the array(xorr), the way we'll have xor of two element of x & y that is appear only once
// we'll find the least significant bit(lsb) in x^y, either x or y will have that bit as set 
// because of the property of xorr
// again find the xorr of the array for only those numbers which has lsb has set bit 
// this result will give us as first number i.e x 
// the second number will be xorr ^ x


//link :- https://www.geeksforgeeks.org/problems/finding-the-numbers0215/1

class Solution {
  public:
    vector<int> singleNum(vector<int>& nums) {
        // Code here.
        int xorr = 0, n = nums.size();
        
        for(int i=0; i<n; ++i)
            xorr ^= nums[i];
        
        int lsb = -1, num1 = 0, num2 = 0;
        
        for(int bit=0; bit<32; ++bit){
            if(xorr & (1<<bit)){
                lsb = bit;
                break;
            }
        }
        
        for(int i=0; i<n; ++i){
            if(nums[i] & (1 << lsb))
                num1 ^= nums[i];
        }
        num2 = num1 ^ xorr;
        if(num1 < num2)     return {num1, num2};
        return {num2, num1};
    }
};