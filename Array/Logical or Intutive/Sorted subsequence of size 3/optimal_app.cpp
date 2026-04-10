#include <bits/stdc++.h>
using namespace std; 

// Time complexity :- O(n)
// Space complexity :- O(n)

// Approach :- 
// we've to find the for any element whether a left min element and right max element exist or not 
// for every element we'll find which is largest element on the right 
// and also which is smallest element on the left 
// if any element satisfy the case then it's possible 


// Links :- https://www.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        vector<int> rightMax(n, INT_MIN);
        
        // maintain right max for every index 
        for(int i=n-2; i>=0; --i){
            rightMax[i] = max(arr[i+1], rightMax[i+1]);
        }
        
        int leftMin = arr[0];
        
        for(int i=1; i<n; ++i){
            if(leftMin < arr[i] && arr[i] < rightMax[i]){
                return {leftMin, arr[i], rightMax[i]};
            }
            leftMin = min(leftMin, arr[i]);
        }
        return {};
    }
};