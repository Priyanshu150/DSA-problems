#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*log(n))
// Space complexity :- O(n + n)              

// Approach :- 
// Greedy approach will not work hence we'll use dynamic program
// But as per constraint 1e5 n^2 approach will not work 
// base case will be ind >= n return 0
// try take and notTake case for exploring possibilites 
// intead of going to ind+1, find next index which statisfy the property using bs
// we can use 1d dp array to memoize the solution 


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
  
    int solve(int ind, int &n, vector<vector<int>> &jobs, vector<int> &dp){
        // base case 
        if(ind >= n){
            return 0;
        }
        if(dp[ind] != -1)
            return dp[ind];
        
        // move the next index without taking the current one 
        int notTake = solve(ind+1, n, jobs, dp);
        // find the next index using binary search 
        int nextInd = search(ind+1, jobs[ind][1], n, jobs);
        // take the current index along with the profit 
        int take = jobs[ind][2] + solve(nextInd, n, jobs, dp);
        
        // answer will be max of take or not take 
        return dp[ind] = max(notTake, take);
    }
  
  public:
    int maxProfit(vector<vector<int>> &jobs) {
        int n = jobs.size();
        // sort the jobs by timinigs 
        sort(jobs.begin(), jobs.end());
        // intialize dp 
        vector<int> dp(n, -1);
        // try out all possibilities with recusion 
        return solve(0, n, jobs, dp);
    }
};