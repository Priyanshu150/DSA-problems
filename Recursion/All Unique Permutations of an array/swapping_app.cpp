#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n!)
// Space complexity :- O(n)              

// Approach :- 
// use swapping approach to swap number in-order to create all the possibilities 

// Links :- https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1

class Solution {
  private:
    void solve(int ind, vector<int> temp, int &n, set<vector<int>> &st){
        if(ind == n){
            st.insert(temp);
            return;
        }
        
        for(int i=ind; i<n; ++i){
            swap(temp[i], temp[ind]);
            solve(ind+1, temp, n, st);
            swap(temp[i], temp[ind]);
        }
    }
    
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        set<vector<int>> st;
        solve(0, arr, n, st);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};