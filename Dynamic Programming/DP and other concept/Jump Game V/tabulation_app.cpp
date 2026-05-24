#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n) + (n+d))
// Space complexity :- O(n*2)

// Approach :-  
// If we directly convert the memoization into tabulation it will not work
// as we've to calculate i-x to i+x values for i index, for all 0 < x <= d
// so we'll solve for the lower value first which is mentioned in the problem statement 
// hence we'll sort the array and then apply the same solution 
// it'll give us a valid answer 


// Link :- https://leetcode.com/problems/jump-game-v/description/

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int result = 1;
        int n = arr.size();
        // intialise dp with default value of 1 
        vector<int> dp(n, 1);
        vector<pair<int,int>> temp;

        // maintain an array in format: {arr[i], i}
        for(int i=0; i<n; ++i){
            temp.push_back({arr[i], i});
        }
        // sort the array based on the value in non-descending order 
        sort(begin(temp), end(temp));

        for(auto it: temp){
            int val = it.first;
            int ind = it.second;

            // jump on the left side 
            for(int i=ind-1; i>=max(0, ind-d); --i){
                // invalid jump condition 
                if(arr[i] >= arr[ind])
                    break;
                
                dp[ind] = max(dp[ind], 1 + dp[i]);
            }

            // jump on the right side
            for(int i=ind+1; i<=min(n-1, ind+d); ++i){
                // invalid jump condition 
                if(arr[i] >= arr[ind])
                    break;
                
                dp[ind] = max(dp[ind], 1 + dp[i]);
            }
            result = max(result, dp[ind]);
        }
        return result;
    }
};