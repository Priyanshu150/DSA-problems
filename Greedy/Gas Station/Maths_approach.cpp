#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)            // Where n is length of array
// Space complexity :- O(1)          

// Approach :-
// If total_fuel_value - total_dist_travelled >= 0, then only its possible to complete circular journey
// For index, we can assume that current index is valid but if the somehow will not able to reach with current index
// then we will change the ans_index to curr_ind + 1
// If starting from that index we get a -ve fuel balance then it's not possible
// Since the question mentioned that there is 1 answer possible the we can say that we'll get answer using this approach


// Links :- https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n = gas.size(), diffSum = 0, index = 0, fuel = 0;
        
        for(int i=0; i<n; ++i){
            int diff = gas[i] - cost[i];
            diffSum += diff;
            fuel += diff;
            if(fuel < 0){
                fuel = 0;
                index = i+1;
            }
        }
        return (diffSum < 0) ? -1 : index;
    }
};
