#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1) 

// Approach :-
// the first point starting point left to right where the condition satisfy 
// arr[i] > (i+k) will be our answer 
// why ? because index will be sequencial and that will satisfy the property of logical counting 
// if the value at index is greater than (i+k) that is breaking point for us 

//link :- https://www.geeksforgeeks.org/problems/kth-missing-positive-number-in-a-sorted-array/1

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n = arr.size();
        
        for(int i=0; i<n; ++i){
            if(arr[i] > (i+k)){
                return i+k;
            }
        }
        return n+k;
    }
};