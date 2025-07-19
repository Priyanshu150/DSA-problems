#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(log(n))   
//Space complexity :- O(1)

// Approach :-
// use standard binary search technique on index
// if the mid is equal to target return from that point with mid as answer
// otherwise there will be 2 case, if left or right part is sorted 
// when left part is, then check wheather the number is lying in the sorted part if yes 
// then high = mid-1 otherwise low = mid+1
// when right part is, then check wheather the number is lying in the sorted part if yes 
// then low = mid+1 otherwise high = mid-1


//Link :- https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
  public:
    int search(vector<int>& arr, int target) {
        // complete the function here
        int n = arr.size(), low = 0, high = n-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            // Element is present at mid
            if(arr[mid] == target)
                return mid;
            // Left part is sorted
            else if(arr[low] <= arr[mid]){
                //If present in sorted part
                if(target >= arr[low] && target <= arr[mid])
                    high = mid-1;
                //If not present in sorted part 
                else
                    low = mid+1;
            }
            //Right part is sorted
            else{
                //If present in sorted part
                if(target <= arr[high] && target >= arr[mid])
                    low = mid+1;
                //If not present in sorted part 
                else
                    high = mid-1;
            } 
        }
        return -1;
    }
};