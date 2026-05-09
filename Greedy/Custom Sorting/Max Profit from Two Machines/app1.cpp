#include <bits/stdc++.h>

// Time complexity :- O(n * log(n))
// Space complexity :- O(n)

// Approach :-  
// maintain a array with difference b/w two cost of robot doing task 
// sort them based on the absolute diff value 
// take the higher value of the cost/profit from the sorted value
//  until x or y is valid for respective robot 


// Links :- https://www.geeksforgeeks.org/problems/max-profit-from-two-machines/1

class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        int n = arr.size();
        vector<vector<int> > diff;
        
        for(int i=0; i<n; ++i){
            int absVal = abs(arr[i] - brr[i]);
            diff.push_back({absVal, arr[i], brr[i]});
        }
        sort(diff.begin(), diff.end(), [&](vector<int> &v1, vector<int> &v2){
            return v1[0] > v2[0];
        });
        long long res = 0;
        
        for(int i=0; i<n; ++i){
            if(x == 0)          res += diff[i][2];
            else if(y == 0)     res += diff[i][1];
            else if(diff[i][1] > diff[i][2]){
                res += diff[i][1];
                x--;
            }
            else{
                res += diff[i][2];
                y--;
            }
        }
        return res;
    }
};