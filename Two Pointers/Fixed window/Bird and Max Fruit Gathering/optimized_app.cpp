#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(1) 

// Approach :-
// even the question is about find the maximum sum of m consecutive elements in a circular array, we can still use the sliding window technique to solve this problem efficiently.
// We can use a sliding window of size m to find the maximum sum of m consecutive elements in the array.
// we'll traverse at max till (n+m) to cover the circular nature of the array.
// since the array is circular, we can use the modulo operator to wrap around the array when the right pointer exceeds the size of the array.


//link :- https://www.geeksforgeeks.org/problems/bird-and-maximum-fruit-gathering--170645/1

class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size(), sum = 0;
        
        // find the sum of first m elements 
        for(int right=0; right<m; ++right){
            sum += arr[right];
        }
        int left = 0, right = m; 
        int maxSum = sum;
        
        // maintain a sliding window of size m 
        while(right < (n+m)){
            sum += arr[right % n];
            ++right;
            
            sum -= arr[left % n];
            ++left;
            
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};