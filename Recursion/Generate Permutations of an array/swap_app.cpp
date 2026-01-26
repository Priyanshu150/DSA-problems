#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O()
// Space complexity :- O()

// Approach :-  
// use recusion to  generate all the permutation 
// traverse from start to end from current index
// swap current and next choosen index 
// explore all the possibilities using recusion 
// backtracts to the previous state 


// link :- 
// gfg - https://www.geeksforgeeks.org/problems/generate-permutations-of-an-array/1
// leetcode - https://leetcode.com/problems/permutations/description/

class Solution {
  private:
    void solve(int ind, int &n, vector<int> arr, vector<vector<int>> &ans){
        // base case 
        if(ind == n){
            ans.push_back(arr);
            return;
        }
        
        // traverse from curr_ind to end 
        for(int i=ind; i<n; ++i){
            // swap the curr_index with i to generate all the possible permutation
            swap(arr[i], arr[ind]);
            solve(ind+1, n, arr, ans);
            // backtracts to the previous state 
            swap(arr[i], arr[ind]);
        }
    }
  
  public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        
        solve(0, n, arr, ans);
        return ans;
    }
};