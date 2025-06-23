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
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ind = 1, sum = 1;

        while(ind < n){
            if(ratings[ind] == ratings[ind-1]){
                sum += 1;
                ind += 1;
                continue;
            }
            int peak = 1;
            while(ind < n && ratings[ind] > ratings[ind-1]){
                peak += 1;
                sum += peak;
                ind += 1;
            }

            int down = 1;
            while(ind < n && ratings[ind] < ratings[ind-1]){
                sum += down;
                down += 1;
                ind += 1;
            }
            if(down > peak)     sum += (down - peak);
        } 
        return sum;
    }
};

