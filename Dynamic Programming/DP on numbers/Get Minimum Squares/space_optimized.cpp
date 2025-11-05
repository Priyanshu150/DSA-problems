#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(100*n)
//Space complexity :- O(n)

// Approach :-
// tabulation approach can further optimized to 1-d space optimization 
// using 2 1-d array to store the relevant detials only 
// every first value of array should be 0 i.e. curr[0] = 0, which is base case 

//link :- https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1

class Solution {
  public:
    int minSquares(int n) {
        // Code here
        vector<int> nums;
        
        // create all the valid square combination 
        for(int i=1; i<=100; ++i){
            int prod = i*i;
            nums.push_back(prod);
        }
        // declare two 1d dp vector of size 100*n
        vector<int> curr(n+1, 1e5), ahead(n+1, 135);
        // base case 
        ahead[0] = 0;
        
        for(int ind=99; ind>=0; --ind){
            curr[0] = 0;
            for(int sum=1; sum<=n; ++sum){
                // not take the current number and move to next 
                curr[sum] = ahead[sum];
                // take the current number if number is less than target 
                if(nums[ind] <= sum){
                    // the min of both possibilities will be our answer
                    curr[sum] = min(curr[sum], 1 + curr[sum - nums[ind]]);   
                }
            }
            ahead = curr;
        }
        return ahead[n];
    }
};