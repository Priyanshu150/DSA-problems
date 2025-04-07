#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*s)  
// Space complexity :- O(n)

// Approach :-  
// For diving the array into two subset having same sum, the sum of the array should be even
// if it's odd it will not be possible
// if it's even, then we'll check wheather we can find sum/2 in the array
// if we can then other subset will also have the sum/2 total sum
// we can isSubsetSum problem to find that using arr can we make sum/2 as desired

// Link :- 
// (gfg) https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1
// (leetcode) https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
  private:
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
  
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = 0, n = arr.size();
        sum = accumulate(arr.begin(), arr.end(), sum);
        
        if(sum % 2)     return false;
        return isSubsetSum(arr, sum/2);
    }
};

class Solution {
  private:
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
  
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = 0, n = arr.size();
        sum = accumulate(arr.begin(), arr.end(), sum);
        
        if(sum % 2)     return false;
        return isSubsetSum(arr, sum/2);
    }
};