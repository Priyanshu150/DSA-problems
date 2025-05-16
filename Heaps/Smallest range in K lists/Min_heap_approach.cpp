#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*k)
// Space complexity :- O(k*3)

// Approach :-  
// use min heap to store number in the format {number, array_number, index}
// Initially push first element of each number into the minHeap
// For each iteration maintain a minimum and maximum element which will be our range
// after each iteration the element that will be left in the heap will be exactly k from each array
// maintain a maxiumum variable which will maintain the maximum value seen till now 
// and minimum can be find at the root of the minHeap
// calculate the range using these variables and mainatain the lowest range answer


//Link :- https://www.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1

class Solution {
    #define vi vector<int>
    
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // code here
        int len = 1e6, lt, rt, maxi = -1;
        int n = arr[0].size(), k = arr.size();
        priority_queue<vi, vector<vi>, greater<vi>> pq;
        
        for(int i=0; i<k; ++i){
            maxi = max(maxi, arr[i][0]);
            pq.push({arr[i][0], i, 0});
        }
        
        while(pq.size() == k){
            vi curr = pq.top();
            pq.pop();
            
            int val = curr[0], arrayNo = curr[1], ind = curr[2];
            
            if((maxi - val) < len){
                len = maxi - val;
                lt = val;
                rt = maxi;
            }
            if(ind+1 < n){
                maxi = max(arr[arrayNo][ind+1], maxi);
                pq.push({arr[arrayNo][ind+1], arrayNo, ind+1});
            }
        }
        return {lt, rt};
    }
};