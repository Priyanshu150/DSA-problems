#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^2 * log(n^2))  
// Space complexity :- O(n^2)

// Approach :-
// create all the subarray from the array 
// store the sum of each sub-array into the min heap 
// whenever size increase from k after adding remove the top element 
// at last, on top we'll have our answer


// Link :- https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i=0; i<n; ++i){
            int sum = 0;
            for(int j=i; j<n; ++j){
                sum += arr[j];
                minHeap.push(sum);
                if(minHeap.size() > k)
                    minHeap.pop();
            }
        }
        return minHeap.top();
    }
};