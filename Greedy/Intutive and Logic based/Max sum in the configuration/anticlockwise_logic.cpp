#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)   
//Space complexity :- O(1)

// Approach :- 
// calculate the current value of (arr[i]*i) and sum of the array 
// assume rotate the array left side i.e. counterclockwise
// next value will be prevSum + (arr[i-1]*n) - sum
// shifting everything to the left means first element will be the last 
// and contirbution of every element will decrease by 1 i.e. sum of the array 
// last element get increased by n times since 1 contribution is already substracted 

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
        
        // travere 1 to n asuming that we'll rotate left side i.e. counterclockwise
        // i.e. arr[i] will move to arr[i-1]
        for(int i=1; i<n; ++i){
            // prev value + arr[i-1]*n(it moves to last) - 1 contribution of each element(sum) 
            // will be the new value of the element 
            prevSum = prevSum + (arr[i-1]*n) - sum;
            res = max(prevSum, res);
        }
        return res;
    }
};