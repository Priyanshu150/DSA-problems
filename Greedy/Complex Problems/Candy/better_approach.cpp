#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Traverse the left to right in the rating array and assign the candies 
// based on the condition ratings[i-1] < rating[i], then candie[i] = candies[i-1]
// repeat the same from right to left, but this time take maximum so that is satifies both condition
// candies[i] will be max(prev_val of candies[i], 1 + candies[i+1])


//Link :- 
// leetcode - https://leetcode.com/problems/candy/
// gfg - https://www.geeksforgeeks.org/problems/candy/1

class Solution {
  public:
    int minCandy(vector<int> &arr) {
        int n = arr.size();
        
        if(n == 1)      return 1; 
        
        vector<int> candies(n, 1);
        
        // traverse from left to right 
        for(int i=1; i<n; ++i){
            // update the candies count based on higher rank 
            if(arr[i] > arr[i-1]){
                candies[i] = (candies[i-1]+1);
            }
        }
        int res = candies[n-1];
        
        // traverse from right to left 
        for(int i=n-2; i>=0; --i){
            // update the candies based on higher rank if not already updated 
            if(arr[i] > arr[i+1] && candies[i] <= candies[i+1]){
                candies[i] = (candies[i+1]+1);
            }
            res += candies[i];
        }
        return res;
    }
};