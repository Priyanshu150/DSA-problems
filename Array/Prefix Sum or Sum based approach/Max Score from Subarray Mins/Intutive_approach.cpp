#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// In order to maximize the sum, we've to consider adjacent element which have maximum sum
// to maximize sum we've to take maximum element into our sub-array 
// including more than 2 element in subarray means we lost the capability to add maximum element 

// links :- https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/1

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size(), res = 0;
        
        for(int i=1; i<n; ++i){
            res = max(res, arr[i]+arr[i-1]);
        }
        return res;
    }
};
