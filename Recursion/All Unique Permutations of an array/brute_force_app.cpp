#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n!)
// Space complexity :- O(n + n)              

// Approach :- 
// try creating all the possibilities and mark them if they are considered using hash array
// recursion will be try all possibities and backtrack 

// Links :- https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1

class Solution {
  private:
    int n;
    set<vector<int>> st;
    vector<int> num;
    
    void solve(vector<int> temp, vector<bool> taken){
        if(temp.size() == n){
            st.insert(temp);
            return;
        }
        
        for(int ind = 0; ind<n; ++ind){
            if(taken[ind] == false){
                taken[ind] = true;
                temp.push_back(num[ind]);
                
                solve(temp, taken);
                
                taken[ind] = false;
                temp.pop_back();
            }
        }
    }
  
  public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        n = arr.size();
        num = arr;
        vector<int> temp;
        vector<bool> taken(n, false);
        solve(temp, taken);
        
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};