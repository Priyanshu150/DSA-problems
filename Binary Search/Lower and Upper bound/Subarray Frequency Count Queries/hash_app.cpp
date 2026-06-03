#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(N*log(N) + Q*log(K))
// Space complexity :- O(N)

// Approach :- 
// for every element hash the values of all the index present into an array 
// for every query, check if the value is presnt 
// if present then using upper and lower bound count the number of occurence 

// Link :- https://www.geeksforgeeks.org/problems/count-frequency-of-an-element-in-a-given-range/1

class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mp;     // ele -> {ind1, ind2, .....}
        int n = arr.size(), q = queries.size();
        
        // element to index mapping 
        for(int i=0; i<n; ++i){
            int ele = arr[i];
            mp[ele].push_back(i);
        }
        vector<int> ans;
        
        for(int i=0; i<q; ++i){
            // find the left, right, x value 
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];
            
            // x is not present in complete array 
            if(mp.count(x) == 0){
                ans.push_back(0);
                continue;
            }
            // find the array of index where x is present 
            vector<int> temp = mp[x];
            // find the first index where the x is present 
            auto left = lower_bound(temp.begin(), temp.end(), l);
            // find the last index where the x is present + 1
            auto right = upper_bound(temp.begin(), temp.end(), r); 
            // diff b/w them will be count of time they appeared 
            ans.push_back(right - left);
        }
        return ans;
    }
};