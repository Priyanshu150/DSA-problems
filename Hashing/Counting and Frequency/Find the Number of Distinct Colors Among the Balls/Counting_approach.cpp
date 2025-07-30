#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Use counting + hashing approach to solve this problem
// Create two unordered hash map and for tracking purpose 
// Take each query at a time, 
// Store which ball is marked with which color in first hash map
// Use 2nd hash map to count for each color how many balls are marked
// If any ball is not marked then color that ball put it in respective hash map
// If that ball is already colored then fetch the prev color and removed that color contribution for 2nd map
// if any color has count equals to 0 remove it from map
// Track ans from the 2nd hash map after every query 

// Link :- https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int,int> ballColor, distintColor;

        for(auto query: queries){
            int ball = query[0], color = query[1];

            if(ballColor.count(ball)){
                int prevColor = ballColor[ball];
                distintColor[prevColor] -= 1;

                if(distintColor[prevColor] == 0)
                    distintColor.erase(prevColor);
            }

            ballColor[ball] = color;
            distintColor[color] += 1;
            ans.push_back(distintColor.size());
        }
        return ans;
    }
};