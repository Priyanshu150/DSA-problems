#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m)  
// Space complexity :- O(1)

// Approach :- 
// we'll using the same concept as of the better_approach of same problem 
// but here we'll do in single pass using kadanes algorithm 

// Link :- https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n = arr.size(), sum = 0;
        int min_straight_sum = INT_MAX, temp_min_sum = 0;
        int max_straight_sum = INT_MIN, temp_max_sum = 0;
        
        for(int i=0; i<n; ++i){
            sum += arr[i];
            
            temp_min_sum += arr[i];
            min_straight_sum = min(temp_min_sum, min_straight_sum);
            if(temp_min_sum > 0)        temp_min_sum = 0;
            
            temp_max_sum += arr[i];
            max_straight_sum = max(max_straight_sum, temp_max_sum);
            if(temp_max_sum < 0)        temp_max_sum = 0;
        }
        if(min_straight_sum == sum)
            return max_straight_sum;
        
        return max(max_straight_sum, sum-min_straight_sum);
    }
};