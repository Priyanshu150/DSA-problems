#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*m)
//Space complexity :- O(1)

// Approach :-
// to generate every row of the triangle we can use combination formula 
// If we further analyze the combination we can break that into optimized formula
// for ex of row 5 :- 5/1 , 5*4/1*2, 5*4*3/1*2*3, these will the value of each cell
// use for loop we can form this formula and generate the entire triangle 

//link :- https://leetcode.com/problems/pascals-triangle/

class Solution {
private:
    vector<int> generateRow(int rowNum){
        if(rowNum == 0)     return {1};

        vector<int> res;
        int prev = 1;
        res.push_back(prev);

        for(int i=1; i<rowNum; ++i){
            prev *= (rowNum-i+1);
            prev /= i;
            res.push_back(prev);
        }
        res.push_back(1);
        return res;
    }

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int row=0; row<numRows; ++row){
            vector<int> temp = generateRow(row);
            ans.push_back(temp);
        }
        return ans;
    }
};