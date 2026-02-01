#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N) 

//Approach :-
// Traverse the array from left to right and maitain a deque with the index of array
// front of queue will always have maximum value and we'll push elemnt index from back side
// whenever new elements comes in push pop the indexes until thoses indexes value are less than or equal to current_element
// that way we'll maintain the highest at the front
// Then push the index of that element into the stack
// if(curr_ind - index at front of deque is >= k-1) that means that index is out of our window pop front from the queue
// At last fetch the result from front of the deque


//link :- https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq;
        vector<int> ans;
        
        // traverse on each element of array and store the index 
        for(int i=0; i<n; ++i){
            // maintain a monotonic deque based on index
            while(!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();
            
            // add current element in deque
            dq.push_back(i);
            
            // remove the element out of window 
            if((i - dq.front()) == k)
                dq.pop_front();
            
            // for k size window, answer will be index at front 
            if(i >= k-1){
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
};