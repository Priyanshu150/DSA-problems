#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(N)
// Space complexity :- O(1)

// Approach :-   

//Link :- https://www.geeksforgeeks.org/problems/sum-of-xor-of-all-possible-subsets/1

// approach 1:- 
class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size(), xorr = 0;
        
        // xor of array 
        for(auto num: arr){
            xorr |= num;
        }
        
        int times = (1 << (n-1));
        return xorr << n-1;
    }
};

// approach 2 :- 
class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size(), xorr = 0;
        
        // xor of array 
        for(auto num: arr){
            xorr |= num;
        }
        
        int times = (1 << (n-1));
        return xorr * (1<<(n-1));
    }
};