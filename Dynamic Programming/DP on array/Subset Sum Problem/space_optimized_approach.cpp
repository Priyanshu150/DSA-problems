#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*s)  
// Space complexity :- O(n)

// Approach :-  
// further space can be optimized from tabulation
// as we're only needing previous row to calculate our answer 
// we can keep track of only 2 array that will suffice (prev & curr)
// the base cases and possibilites remains same from the tabulation only the array changes
// dp[ind] to curr and dp[ind-1] to prev
// After every iteration of sum prev becomes equal to curr

// Link :- https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<bool> prev(sum+1, false), curr(sum+1, false);
        
        for(int s=1; s<=sum; ++s){
            if(s == arr[0])
                prev[s] = true;
        }
        prev[0] = true;
        
        for(int ind=1; ind<n; ++ind){
            curr[0] = true;
            for(int s=1; s<=sum; ++s){
                curr[s] = prev[s];
                
                if(arr[ind] <= s)
                    curr[s] = curr[s] | prev[s-arr[ind]];
            }
            prev = curr;
        }
        return prev[sum];
    }
};

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<bool> prev(sum+1, false), curr(sum+1, false);
        prev[0] = true;
        
        for(int ind=1; ind<=n; ++ind){
            curr[0] = true;
            for(int s=1; s<=sum; ++s){
                curr[s] = prev[s];
                
                if(arr[ind-1] <= s)
                    curr[s] = curr[s] | prev[s-arr[ind-1]];
            }
            prev = curr;
        }
        return prev[sum];
    }
};