#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m*log(n*m))
// Space complexity :- O(n*m)

// Approach :-  
// For find the min operation we should make all the element in the matrix equal to target value
// our target value should be meidan of the sorted value of all the element of the matrix
// Element in matrix will always be even we can choose any one b/w the two middle element of sorted values
// for find operation on every element, take diff of the target value and current number
// if the difference is not divisible by x then the operation for that number is not possible return -1
// otherwise if divisible then the number of steps will be diff/x for current number

//Link :- https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        vector<int> temp;

        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                temp.push_back(grid[row][col]);
            }
        }
        sort(temp.begin(), temp.end());
        int mid = (n*m)/2, ele = temp[mid], res = 0;

        for(auto num: temp){
            int val = abs(num - ele);
            if(val%x)   return -1;
            res += (val/x);
        }
        return res;
    }
};