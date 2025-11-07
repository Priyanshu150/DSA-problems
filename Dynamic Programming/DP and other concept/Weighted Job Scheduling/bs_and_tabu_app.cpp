#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*log(n))
// Space complexity :- O(n)           

// Approach :- 
// for tabulation approach, base case will be all the value will be 0 initially 
// ind will go from n-1 to 0, express the same possibilities 
// and answer will be stored at dp[0]

// Links :- https://www.geeksforgeeks.org/problems/weighted-job-scheduling/1

class Solution {
  private:
    int search(int ind, int endTime, int &n, vector<vector<int>> &jobs){
        int low = ind, high = n-1, res = n;
        
        // standard bs 
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(endTime <= jobs[mid][0]){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
    
  public:
    int maxProfit(vector<vector<int>> &jobs) {
        int n = jobs.size();
        // sort the jobs by timinigs 
        sort(jobs.begin(), jobs.end());
        // intialize dp 
        vector<int> dp(n+2, 0);
        
        // tabulation approach
        for(int ind=n-1; ind>=0; --ind){
            // move the next index without taking the current one 
            dp[ind] = dp[ind+1];
            // find the next index using binary search 
            int nextInd = search(ind+1, jobs[ind][1], n, jobs);
            // take the current index along with the profit 
            dp[ind] = max(dp[ind], jobs[ind][2] + dp[nextInd]);
        }
        return dp[0];
    }
};