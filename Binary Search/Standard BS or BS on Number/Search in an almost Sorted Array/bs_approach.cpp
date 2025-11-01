#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(log(n))  
// Space complexity :- O(1)

// Approach :-
// if a elemenet is shifted and can be either at i, i-1 and i+1 then
// while checking for mid we can check for mid-1 and mid+1 also 
// and rest template of bs remains same 

// Link :- https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1

class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int n = arr.size(), low = 0, high = n-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] == target)
                return mid;
            else if(mid-1 >= 0 && arr[mid-1] == target)
                return mid-1;
            else if(mid+1 < n && arr[mid+1] == target)
                return mid+1;
            else if(arr[mid] < target)
                low = mid+2;
            else 
                high = mid-2;
        }
        return -1;
    }
};