#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n*log(n))
// Space complexity :- O(n)

// Approach :- 
// Hash all the value by squaring values them
// Traverse on the array and pick two value and find the squared sum of them in the hash 
// if present then return true otherwise return false at last 


// Link :- https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1

class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; ++i){
            mp[arr[i] * arr[i]] = 1;
        }
        
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                int val = arr[i]*arr[i] + arr[j]*arr[j];
                if(mp.count(val))
                    return true;
            }
        }
        return false;
    }
};