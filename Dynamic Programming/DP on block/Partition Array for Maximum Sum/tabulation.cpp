#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N^2)
//Space complexity :- O(N) 

// Approach :-
// for base case, initailize all the values to 0
// for ind, go from n-1 to 0
// copy the reucurence 
// the answer will be stored at dp[0]


//link :- https://leetcode.com/problems/partition-array-for-maximum-sum/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for(int ind=n-1; ind>=0; --ind){
            int maxi = 0;

            for(int i=ind; i<min(n, ind+k); ++i){
                maxi = max(maxi, arr[i]);
                int val = maxi*(i - ind + 1) + dp[i+1];
                dp[ind] = max(dp[ind], val);
            }
        }
        return dp[0];
    }
};
