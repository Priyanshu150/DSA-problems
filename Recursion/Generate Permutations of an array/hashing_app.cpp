#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O()
// Space complexity :- O()

// Approach :-  
// try taken each element one by one and use recursion 
// add the element to the array and mark the taken one as true 
// backtracts to the previous states once  explore all using current 


// link :- 
// gfg - https://www.geeksforgeeks.org/problems/generate-permutations-of-an-array/1
// leetcode - https://leetcode.com/problems/permutations/description/

class Solution {
  private:
    void solve(int ind, int &n, vector<int> arr, vector<bool> &taken, 
        vector<int> &temp, vector<vector<int>> &ans){
        
        // base case when all the element are taken 
        if(ind == n){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0; i<n; ++i){
            if(!taken[i]){
                // mark the current element as taken 
                taken[i] = true;
                // add the current element into array 
                temp.push_back(arr[i]);
                // call the recursion further to find all permutation 
                solve(ind+1, n, arr, taken, temp, ans);
                // backtract to the previous state'
                taken[i] = false;
                temp.pop_back();
            }
        }
    }
  
  public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp;
        vector<bool> taken(n, false);
        vector<vector<int>> ans;
        
        solve(0, n, arr, taken, temp, ans);
        
        return ans;
    }
};