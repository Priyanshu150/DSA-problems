#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(q*n)
// Space complexity :- O(1)

// Approach :- 
// traverse on every subarray and caluclate the mean value of that 

// Links :- https://www.geeksforgeeks.org/problems/mean-of-range-in-array2123/1

class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        vector<int> ans;
        
        for(auto query: queries){
            int l = query[0];
            int r = query[1];
            
            int sum = 0, cnt = 0;
            
            for(int i=l; i<=r; ++i){
                sum += arr[i];
                cnt += 1;
            }
            int mean = (sum / cnt);
            ans.push_back(mean);
        }
        return ans;
    }
};