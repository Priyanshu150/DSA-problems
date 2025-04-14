#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*N)
// Space complexity :- O(1)

// Approach :-
// sum of n natural number is n*(n+1)/2
// sum of n natural squared number is n*(n+1)*(2*n+1)/6
// we can calulate the sum(sum) and square_sum(sqrSum) from the number available in the grid
// sumDiff = x - y = sum - n*(n+1)/2
// sqrDiff = x^2 - y^2 = sqrSum - n*(n+1)*(2*n+1)/6
// repeat will be (sqrDiff / sumDiff + sumDiff) / 2
// missing will be (sqrDiff / sumDiff - sumDiff) / 2

// Link :- https://leetcode.com/problems/find-missing-and-repeated-values/description/

class Solution {
private:
    #define ll long long 

public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        ll n = grid.size(), total = n*n, sum = 0, sqrSum = 0;

        for(int row=0; row<n; ++row){
            for(int col=0; col<n; ++col){
                sum += grid[row][col];
                sqrSum += static_cast<ll>(grid[row][col] * grid[row][col]);
            }
        }
        ll sumDiff = sum - total * (total + 1) / 2;
        ll sqrDiff = sqrSum - total * (total+1) * (2*total + 1) / 6;

        int repeat = (sqrDiff / sumDiff + sumDiff) / 2;
        int missing = (sqrDiff / sumDiff - sumDiff) / 2;

        return {repeat, missing};
    }
};