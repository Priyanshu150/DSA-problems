#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// For each value store the index in the map 
// traverse from smaller to larger value in map and check the index for that value in map
// Check the neigbouring index of the curr_ind and assign the candies respectively


//Link :- 
// leetcode - https://leetcode.com/problems/candy/
// gfg - https://www.geeksforgeeks.org/problems/candy/1


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), res = 0;
        vector<int> candies(n, 0);
        map<int, vector<int>> mp;

        for(int i=0; i<n; ++i){
            mp[ratings[i]].push_back(i);
        }

        for(auto it: mp){
            for(auto ind: it.second){
                int candy = 1;
                if(ind-1 >= 0 && ratings[ind-1] < ratings[ind])
                    candy = max(candy, candies[ind-1]+1);
                
                if(ind+1 < n && ratings[ind+1] < ratings[ind])
                    candy = max(candy, candies[ind+1]+1);
                
                candies[ind] = candy;
                res += candy;
            }
        }
        return res;
    }
};