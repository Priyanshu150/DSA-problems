#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(log(n))   
//Space complexity :- O(1)

// Approach :- 
// If we find the index which is greater than it's next neighbour 
// then (index+1) time it will be rotated 
// write a corner case for 1 and n-1 rotation i.e. first and last element 
// otherwise apply binary search on the range 1 to n-1 to find the index 
// elminate the portion which is sorted and search in the other one 

//Link :- https://www.geeksforgeeks.org/problems/rotation4723/1

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        // base case 
        if(n == 1)
            return 0;
        
        // array is rotated 1 time 
        if(arr[0] > arr[1])
            return 1;
        
        // array is rotated n-1 time
        if(arr[n-2] > arr[n-1])
            return n-1;
        
        int low = 1, high = n-2, res = 0;
        
        // standard bs 
        while(low <= high){
            int mid = low + (high - low)/2;
            
            //mid-1 index is greater than mid, than means it's rotated by mid times
            if(arr[mid-1] > arr[mid]){
                return mid;
            }
            //mid index is greater than mid+1, than means it's rotated by mid+1 times
            else if(arr[mid] > arr[mid+1]){
                return mid+1;
            }
            // left portion is sorted, then discard it and search in right portion
            else if(arr[low] < arr[mid]){
                low = mid+1;
            }
            // rigt portion is sorted, then discard it and search in left portion
            else{
                high = mid-1;
            }
        }
        return res;
    }
};
