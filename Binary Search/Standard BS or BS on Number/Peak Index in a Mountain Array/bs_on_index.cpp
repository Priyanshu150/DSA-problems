#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(log(n))   
//Space complexity :- O(1)

// Approach :-
// use standard binary search on index
// handle the edge cases i.e index 0 and n-1  seprately
// compare the mid element with neighbours if it's peak element return it as answer 
// otherwise check if we're at increasing curve then answer must lie on left side i.e. low = mid+1;
// otherwise use high = mid-1 which indicates we're at the decreasing curve


//Link :- https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(arr[0] > arr[1])         return 0;
        if(arr[n-2] < arr[n-1])     return n-1;

        int low = 1, high = n-2;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid;
            else if(arr[mid-1] < arr[mid])
                low = mid+1;
            else 
                high = mid-1;
        }
        return -1;
    }
};