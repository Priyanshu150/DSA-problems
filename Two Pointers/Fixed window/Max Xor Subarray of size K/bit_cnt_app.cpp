#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(32)

// Approach :-
// calculate the xor for every window of size k
// for every window count the xorr using frequency array 
// if a bit has odd frequency that means it'll be set in that window
// using that logic we can calculate the xorr of the sub-array 

//link :- https://www.geeksforgeeks.org/problems/max-xor-subarray-of-size-k/1

class Solution {
  private:
    void updateContri(vector<int> &bits, int num, int contri){
        // for every 32 bits 
        for(int bit=0; bit<32; ++bit){
            // check if the bit is set or not 
            if(num & (1<<bit)){
                // update the contribution of current bit 
                bits[bit] += contri;
            }
        }
    }
    
    int findValue(vector<int> &bits){
        int num = 0;
        
        // for every 32 bits 
        for(int bit=0; bit<32; ++bit){
            // current bit has odd contribution
            if(bits[bit] % 2){
                // condition satisfy then xorr of that bit will set for that bit 
                num |= (1 << bit);
            }
        }
        return num;
    }
  
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size(), left = 0, res = 0; 
        vector<int> bits(32, 0);
        
        // maintain a silding window of length k from index [left, right]
        for(int right=0; right<n; ++right){
            // add the contribution of the current number 
            updateContri(bits, arr[right], 1);
            
            if((right-left+1) == k){
                // find the current xorr value and update the max answer 
                res = max(res, findValue(bits));
                // remove the contribution of the current number 
                updateContri(bits, arr[left], -1);
                // move the left pointer 
                left++;
            }
        }
        return res;
    }
};