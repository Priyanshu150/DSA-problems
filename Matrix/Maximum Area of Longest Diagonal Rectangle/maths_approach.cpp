#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*2)
// Space complexity :- O(1)

// Approach :-  
// for diagonal finding use pythagoras theorem and avoid square rooting l^2 + w^2
// use iterative method to calculate the area and maxDiagonal 


// Link :- https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/


class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0, maxDiagonal = 0;

        for(auto dimension: dimensions){
            int length = dimension[0], width = dimension[1];
            int diagonal = length*length + width*width;

            if(diagonal > maxDiagonal){
                maxDiagonal = diagonal;
                area = length*width;
            }
            else if(diagonal == maxDiagonal){
                area = max(area, length*width);
            }
        }
        return area;
    }
};