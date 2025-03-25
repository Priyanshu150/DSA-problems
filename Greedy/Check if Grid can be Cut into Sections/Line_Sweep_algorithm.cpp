#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// Use line sweep alogrithm, representing ending with 0/-1 and starting 1 so that end comes first
// Segregate the x-cordinates and y-cordinates and sort them 
// Apply line sweep alorithm for every cordinates
// and if we're able to create a line >= 3 then it's possible otherwise not

//Link :- https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/

class Solution {
private:
    bool countLineIntersection(vector<pair<int,int>> &cordinates){
        int lines = 0, overlap = 0;

        for(auto cord: cordinates){
            if(cord.second == 0)    overlap--;
            else    overlap++;

            if(overlap == 0)    
                lines++;
        }
        return (lines >= 3);
    }

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> x_cordinates, y_cordinates;

        for(auto rectangle: rectangles){
            x_cordinates.push_back({rectangle[0], 1});
            x_cordinates.push_back({rectangle[2], 0});
            y_cordinates.push_back({rectangle[1], 1});
            y_cordinates.push_back({rectangle[3], 0});
        }
        sort(x_cordinates.begin(), x_cordinates.end());
        sort(y_cordinates.begin(), y_cordinates.end());

        return (countLineIntersection(x_cordinates) | countLineIntersection(y_cordinates));
    }
};