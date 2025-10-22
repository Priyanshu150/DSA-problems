#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*log(K))
// Space complexity :- O(K)

// Approach :-  
// Keep the next k+1 element in the min heap from current index
// replace the current value with smallest value i.e. top of heap and remove it 

// Link :- https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), right = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(right=0; right<=k; ++right)
            pq.push(arr[right]);
        
        for(int left=0; left<n; ++left){
            arr[left] = pq.top();
            pq.pop();
            
            if(right < n){
                pq.push(arr[right]);
                right++;
            }
        }
    }
};