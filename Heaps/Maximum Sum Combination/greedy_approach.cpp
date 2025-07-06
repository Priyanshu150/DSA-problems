#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// sort both the array 
// for finding the maximum sum we've to take maximum element inorder to find the sum
// we'll use max heap to find maximum sum, string the max_sum and index from both the arrays 
// for every pair index we'll decrease one of the index by 1 
// try to find wheather the new index to were already taken into consideration or not
// if not take the sum and push the indexes into the heap
// repeat this until we found k element 


// links :- https://www.geeksforgeeks.org/problems/maximum-sum-combination/1

class Solution {
  #define pii pair<int, pair<int,int>> 
  
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        vector<int> ans;
        priority_queue<pii> pq;
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        
        pq.push({a[n-1] + b[n-1], {n-1, n-1}});
        vis[n-1][n-1] = true;
        
        while(k--){
            pii it = pq.top();
            pq.pop();
            
            int val = it.first;
            int i = it.second.first;
            int j = it.second.second;
            ans.push_back(val);
            
            if(i-1 >= 0 && vis[i-1][j] == false){
                pq.push({a[i-1] + b[j], {i-1, j}});
                vis[i-1][j] = true;
            }
            if(j-1 >= 0 && vis[i][j-1] == false){
                pq.push({a[i] + b[j-1], {i, j-1}});
                vis[i][j-1] = true;
            }
        }
        return ans;
    }
};