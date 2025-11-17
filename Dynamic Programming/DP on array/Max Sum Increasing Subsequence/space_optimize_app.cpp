#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*n)               
// Space complexity :- O(n)          


// Links :- https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        // initialize a two 1d dp vector with 0
        vector<int> prev(n+2, 0), curr = prev;
        
        for(int ind=1; ind<=n; ++ind){
            for(int nextInd=1; nextInd<=n+1; ++nextInd){
                curr[nextInd] = prev[nextInd];
                
                if(nextInd == n+1 || arr[ind-1] < arr[nextInd-1])
                    curr[nextInd] = max(curr[nextInd], arr[ind-1] + prev[ind]);
            }
            prev = curr;
        }
        return prev[n+1];
    }
};