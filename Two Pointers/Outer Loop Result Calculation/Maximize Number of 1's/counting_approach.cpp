#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// use sliding window approach find a valid window where at most k zeros are there 
// maintain a result which keep the maximum result and store the maximum valid window size 
// remove element from the left side of the window whenever a non-valid window is found 

// link :- https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int  n = arr.size(), left = 0, zeros = 0, res = 0;
        
        for(int right=0; right<n; ++right){
            if(arr[right] == 0)
                zeros++;
                
            while(zeros > k){
                if(arr[left] == 0)
                    zeros--;
                
                ++left;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
