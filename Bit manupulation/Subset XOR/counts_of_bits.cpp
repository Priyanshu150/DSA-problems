#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(N*32 + N)
// Space complexity :- O(1)

// Approach :-   
// For each bit, count the number of set bit 
// if the current bit in given number is set, that means sum of bit should match that requirement 
// if sum of bit is even that mean current bit of number should be 0
// if sum of bit is odd that mean current bit of number should be 1
// following the xor bit property
// if it's not following that we've to remove that number 
// at max only 1 number should be removed otherwise nothing to ber removed 

//Link :- https://www.geeksforgeeks.org/problems/subset-xor--175953/1

class Solution {
  public:
    vector<int> subsetXOR(int n) {
        int num = 0;
        
        // traverse on every possible bit
        for(int bit=0; bit<32; ++bit){
            int setBit = 0, currBit = (n & (1<<bit));
            // traverse on every number 
            for(int i=1; i<=n; ++i){
                // caculate the number of set bits 
                if(i & (1<<bit)){
                    setBit++;
                }
            }
            // check what bit is expected at particular bit number 
            if((setBit % 2 == 1 && currBit == 0) || (setBit % 2 == 0 && currBit > 0)){
                num |= (1<<bit);
            }
        }
        vector<int> ans;
        
        for(int i=1; i<=n; ++i){
            // skip the number which is not contributing 
            if(num == i)
                continue;
            
            ans.push_back(i);
        }
        return ans;
    }
};