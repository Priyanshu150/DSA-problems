#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*N)
// Space complexity :- O(N*N)

// Approach :-
// maintain and array(nums) of n*n+1 for frequency initially which is 0 for all cases
// travrese the array from left to right and for every number in nums update the freq by 1
// Traverse in the (nums) array and check the freq of each element 
// if any element have frequency as 2 that is repeating or any element having freq as 0 that is missing elemnt

// Link :- https://leetcode.com/problems/find-missing-and-repeated-values/description/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> res(2, 0), nums(n*n+1, 0);
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                nums[grid[i][j]] += 1;
            }
        }
        for(int i=1; i<=(n*n); ++i){
            if(nums[i] == 0)
                res[1] = i;
            if(nums[i] == 2)
                res[0] = i;
        }
        return res;
    }
};