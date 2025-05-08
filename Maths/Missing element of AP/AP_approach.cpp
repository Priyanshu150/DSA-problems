#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(1)

// Approach :-
// we'll find the common difference(d) of AP series 
// check the series if at some point the difference doesn't match 
// then b/w the element where difference doesn't match there will be 1 element missing


// Link :- https://www.geeksforgeeks.org/problems/missing-element-of-ap2228/1

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n = arr.size(), diff = arr[1] - arr[0];
        
        for(int i=2; i<n; ++i){
            if(diff > (arr[i] - arr[i-1]))
                return arr[0] + (arr[i] - arr[i-1]);
            
            if(diff < (arr[i] - arr[i-1]))
                return arr[i] - diff;
        }
        return arr[n-1] + diff;
    }
};