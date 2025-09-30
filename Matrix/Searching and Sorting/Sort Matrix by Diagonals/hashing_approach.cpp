#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n*log(n))
// Space complexity :- O(n*n*log(n))

// Approach :-  
// The diagonal difference (row - col) for diagonal will be 
// for lower it'll be +ve, for upper it'll be -ve and main diagonal will have 0 difference
// store them based on diff key in hash map and sort them 
// sort them in opposite fashion, if asc then use desc other if desc then use asc
// that way we can access the element from back side of the array and delete it in constant operation

// link :- https://leetcode.com/problems/sort-matrix-by-diagonals/

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> mp;

        for(int r=0; r<n; ++r){
            for(int c=0; c<n; ++c){
                int diagDiff = r-c;
                mp[diagDiff].push_back(grid[r][c]);
            }
        }

        for(auto &it: mp){
            if(it.first >= 0)
                sort(it.second.begin(), it.second.end());
            else 
                sort(it.second.rbegin(), it.second.rend());
        }

        for(int r=0; r<n; ++r){
            for(int c=0; c<n; ++c){
                int diagDiff = r-c;
                int val = mp[diagDiff].back();
                grid[r][c] = val;
                mp[diagDiff].pop_back();
            }
        }
        return grid;
    }
};



