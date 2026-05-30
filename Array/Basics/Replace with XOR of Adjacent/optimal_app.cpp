#include <bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :- 
// save the element at index 1 and n-2 
// and keep track of previous element for every index 
// update the xorr value using the previous and next value 


// Link :-  https://www.geeksforgeeks.org/problems/replace-with-xor-of-adjacent/1

class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        int n = arr.size();
        // only 1 element is present 
        if(n == 1)
            return;
        
        // save the next value of first element 
        int firstNext = arr[1];
        // save the previous value of last element 
        int lastPrev = arr[n-2];
        // keep maintaining previous value for all element 
        int prevVal = arr[0];
        
        // traverse on the internal elements 
        for(int i=1; i<n-1; ++i){
            // find the xorr value using prev value and value at i+1 index 
            int xorrVal = prevVal ^ arr[i+1];
            // update the current value into previous value 
            prevVal = arr[i];
            // update the xorr value of the array 
            arr[i] = xorrVal;
        }
        // update the repective corner element with formula 
        arr[0] ^= firstNext;
        arr[n-1] ^= lastPrev;
    }
};