#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(N)
// Space complexity :- O(1)

// Approach :-   
// If we create every sequence and check then we'll find that, xorr of subset will be 
// the bit which is set * the weight of that bit 
// weight of that bit will be number of times it repeated
// i.e. 2^(n-1) times because since we're creating a subset so every number will repeat that many times 
// hence the bit are supposed to be repeat that many times 
// For find which bit is set we can use 'OR' operation in the array 
// and we can finally multiply our or result to the weight i.e. OR_Value * 2^(n-1)
// or in other words can also be written as (OR_Value * 1<<(n-1)) and (OR_Value * 1<<(n-1))

//Link :- https://www.geeksforgeeks.org/problems/sum-of-xor-of-all-possible-subsets/1

// approach 1:- 
class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size(), orr = 0;
        
        // xor of array 
        for(auto num: arr){
            orr |= num;
        }
        
        int times = (1 << (n-1));
        return orr << n-1;
    }
};

// approach 2 :- 
class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size(), orr = 0;
        
        // xor of array 
        for(auto num: arr){
            orr |= num;
        }
        
        int times = (1 << (n-1));
        return orr * (1<<(n-1));
    }
};