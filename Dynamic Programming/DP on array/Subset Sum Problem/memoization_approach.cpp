#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*s)  
// Space complexity :- O(n*s*n)

// Approach :-  
// Greedy approach will not work here as we've to try all the possibilities to find wheather sum exist or not 
// There will to 2 changing parameter for us i.e ind, s(sum) at any stage
// we can try all possibilities by considering take and notTake cases
// notTake will be don't consider the currrent element and move on to the next one & sum remains same
// take will be consider the current_element only when the arr[ind] <= s and moved to next ind with new sum target
// finally we'll return (notTake | take), |(or) because even if we find on either side we're good to say that sum exists
// base casees, when s == 0 that means target exist return true
// when ind<0 || ind == 0 (1-based-indexing), return false because we don't find sum to be 0
// when ind == 0 (0-based-indexing), then if the number at index 0 equal the sum then we return true otherwise false

// since there is only 2 chaning state we can memoize the solution using 2-d dp
// changing index are ind, s, so the length of ((N+1)*sum) will suffice

// Link :- https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution {
  private:
    bool helper(int ind, int s, vector<int> &arr, vector<vector<int>> &dp){
        if(s == 0)      return true;
        if(ind == 0){
            if(s == arr[0])     return true;
            return false;
        }
        if(dp[ind][s] != -1)
            return dp[ind][s];
        
        int notTake = helper(ind-1, s, arr, dp), take = false;
        if(arr[ind] <= s)
            take = helper(ind-1, s-arr[ind], arr, dp);
        
        return dp[ind][s] = notTake | take;
    }
  
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return helper(n-1, sum, arr, dp);
    }
};


class Solution {
  private:
    bool helper(int ind, int s, vector<int> &arr, vector<vector<int>> &dp){
        if(s == 0)      return true;
        if(ind < 0)     return false;
        if(dp[ind][s] != -1)
            return dp[ind][s];
        
        int notTake = helper(ind-1, s, arr, dp), take = false;
        if(arr[ind] <= s)
            take = helper(ind-1, s-arr[ind], arr, dp);
        
        return dp[ind][s] = notTake | take;
    }
  
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return helper(n-1, sum, arr, dp);
    }
};

class Solution {
  private:
    bool helper(int ind, int s, vector<int> &arr, vector<vector<int>> &dp){
        if(s == 0)      return true;
        if(ind == 0)     return false;
        if(dp[ind][s] != -1)
            return dp[ind][s];
        
        int notTake = helper(ind-1, s, arr, dp), take = false;
        if(arr[ind-1] <= s)
            take = helper(ind-1, s-arr[ind-1], arr, dp);
        
        return dp[ind][s] = notTake | take;
    }
  
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        return helper(n, sum, arr, dp);
    }
};
