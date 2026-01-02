#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       
//Space complexity :- O(1)    

//Approach :-
//Divide array on the basis on region
// 0 to (low-1) -> 0
// low to (mid-1) -> 1
// mid to high -> unknown
// (high+2) to n -> 2
// Traverse from mid to high and sort the value by swapping them to either to low or high
// Intially mid = 0, high = n-1 which is the unknown region

//link :- 
// interviewbit - https://www.interviewbit.com/problems/sort-by-color/
// gfg - https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n = arr.size(), low = 0, mid = 0, high = n-1;
        
        // 0 to low-1 indexes has all 0 number 
        // low to mid-1 indexes has all 1 number
        // mid to high is unknown region contins all the elements 
        // (high+1) to (n-1) index has all 2 number 
        
        // traverse untill unknown region exists 
        while(mid <= high){
            if(arr[mid] == 0){
                // swap the element at index mid and low and increase the mid ptr
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            }
            else if(arr[mid] == 1){
                // increase the 1's region by moving mid ptr
                mid++;
            }
            else if(arr[mid] == 2){
                // swap the numbers at index mid and high and decrement the high ptr
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};