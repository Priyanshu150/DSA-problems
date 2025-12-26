#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(log(n))
//Space complexity :- O(1) 

// Approach :-
// following the same condition from the iterative approach we'll use binary search on the index
// if an answer is found at mid we'll try to minimize it more 
// otherwise we'll increase the mid

//link :- https://www.geeksforgeeks.org/problems/kth-missing-positive-number-in-a-sorted-array/1

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n = arr.size(), low = 0, high = n-1, res = n;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(mid+k < arr[mid]){
                res = mid;
                high = mid-1;
            }
            else    low = mid+1;
        }
        return res+k;
    }
};