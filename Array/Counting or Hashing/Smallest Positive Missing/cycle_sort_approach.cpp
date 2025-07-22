#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(N)

// Approach :-
// try to place the number which are in range from 1 to n to it's correct position
// the correct position according to our logic will be i+1 == arr[i] 
// i.e at 0 index place 1, 1 index place 2 and so on 
// and traverse the array again the number and check the number which is missing 
// it'll not be at it's correct place 


// Link :- https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        for(int i=0; i<n; ++i){
            // put the number at it's correct place 
            while(arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i]-1]) 
                swap(arr[i], arr[arr[i]-1]);
        }
        // Check for the first missing number 
        for(int i=0; i<n; ++i){
            if(i+1 != arr[i])
                return i+1;
        }
        return n+1;
    }
};
