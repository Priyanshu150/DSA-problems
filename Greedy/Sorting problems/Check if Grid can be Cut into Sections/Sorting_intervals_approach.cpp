#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// Segregate the x-cordinates and y-cordinates and sort them 
// Traverse the cordinates and check maintain a variable storing previous region of rectangle ending
// if the region is ending before next one is starting then we can create a line 
// as soon we able to create 2 lines we can return true telling that it's possbile 
// at every iteration maitain the maximum ending time of by taking maximum of current ending length and previous ending length
// if iteration is over and we were not able to valid  cuts return false

//Link :- https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/


class Solution {
private:
    bool countLineIntersection(vector<pair<int,int>> &cord){
        int lines = 0, end = cord[0].second, sz = cord.size();

        for(int i=1; i<sz; ++i){
            if(end <= cord[i].first)
                lines++;
            
            end = max(end, cord[i].second);
            if(lines == 2)  return true;
        }
        return false;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> xCord, yCord;

        for(auto rectangle: rectangles){
            xCord.push_back({rectangle[0], rectangle[2]});
            yCord.push_back({rectangle[1], rectangle[3]});
        }
        sort(xCord.begin(), xCord.end());
        sort(yCord.begin(), yCord.end());
        return (countLineIntersection(xCord) | countLineIntersection(yCord));
    }
};