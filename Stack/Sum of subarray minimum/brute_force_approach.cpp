#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*N)
// Space complexity :- O(1)

// Approach :-   
// Try creating all the subarrays and finding the minimum element among them
// take the summation of all the minimum element


// links :- https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1

class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int res = 0, n = arr.size();
        
        for(int i=0; i<n; ++i){
            int mini = arr[i];
            for(int j=i; j<n; ++j){
                mini = min(mini, arr[j]);
                res += mini;
            }
        }
        return res;
    }
};