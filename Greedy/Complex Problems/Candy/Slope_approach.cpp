#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// If we express the rating in terms of point and connect those points 
// then we'll get increasing, decreasing or constant curve 
// since we're only concern with sum not the candies give to each child
// while beinging on the increasing curve we can increase the give the increasing pointer to the ratings
// similar if we're on decreasing curve the give the same pointer since we're not concern about rating 
// so even give the candies as (5 4 3 2 1) or (1 2 3 4 5) it'll not matter as we're concerned about sum
// if we're on the constanct curve then the rating will be same 
// Once base case if the decreasing curve is just after increasing curve 
// then there might be chance that we've to manage decreasing curve has more points in that case adjust the ponints accordingly

//Link :- https://leetcode.com/problems/candy/

class Solution {
  public:
    int minCandy(vector<int> &arr) {
        int n = arr.size(), total = n, i = 1;
        
        // traverse from left to right 
        while(i < n){
            // rating of curr child is equal to previous one 
            if(arr[i] == arr[i-1]){
                i++;
                continue;
            }
            
            // find the increasing sequence 
            int peak = 0;
            while(i<n && arr[i] > arr[i-1]){
                peak++;
                total += peak;
                i++;
            }
            
            if(i == n){
                return total;
            }
            
            // to find the decreasing sequence 
            int valley = 0;
            while(i < n && arr[i] < arr[i-1]){
                valley++;
                total += valley;
                ++i;
            }
            /// remove the extra candy added twice 
            total -= min(peak, valley);
        }
        return total;
    }
};
