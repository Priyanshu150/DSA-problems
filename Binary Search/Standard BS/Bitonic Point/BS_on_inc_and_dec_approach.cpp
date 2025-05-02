#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(log(n))  
// Space complexity :- O(1)

// Approach :-
// Since the array is sorted we can use binary serach to find the point
// there will 3 cases if we're applying binary serach
// 1st case :- if mid is the point then return the answer 
// 2nd case :- if the mid is on increasing curve then low has to move to mid+1
// 3rd case :- if the mid is on decreasing curve then high has to move to mid-1
// In any of the above case we've to compare the adjacent element of mid 
// Adjacent element can be out of the bound also to handle that 
// we can check if the first and last element is our bitonic point separately
// and we'll start our low from 1 and high from n-2

// Link :- https://www.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1

class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(arr[0] > arr[1])         return arr[0];
        if(arr[n-1] > arr[n-2])     return arr[n-1];
        
        int low = 1, high = n-2;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid])
                return arr[mid];
            else if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1])
                low = mid+1;
            else 
                high = mid-1;
        }
        return arr[n-1];
    }
};
