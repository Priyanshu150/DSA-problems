#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)   
//Space complexity :- O(1)

// Approach :- 
// follow the same approach as anti-clockwise logic but changing it slightly 

//Link :- https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int sum = 0, prevSum = 0;
        
        // calculate the sum and current value of (i*arr[i])
        for(int i=0; i<n; ++i){
            sum += arr[i];
            prevSum += (arr[i]*i);
        }
        int res = prevSum;
        
        // travere 1 to n asuming that we'll rotate right side i.e. clockwise
        // i.e. arr[i] will move to arr[i+1]
        for(int i=n-2; i>=0; --i){
            // prev value - arr[i-1]*n(it moves to firt) + 1 contribution of each element(sum) 
            // will be the new value of the element 
            prevSum = prevSum - (arr[i+1]*n) + sum;
            res = max(prevSum, res);
        }
        return res;
    }
};