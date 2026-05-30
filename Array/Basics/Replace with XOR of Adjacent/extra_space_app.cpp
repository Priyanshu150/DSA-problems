#include <bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// use temp array to keep track of previous array values 

// Link :-  https://www.geeksforgeeks.org/problems/replace-with-xor-of-adjacent/1

class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp = arr;
        
        if(n == 1)  return;
        
        arr[0] = temp[0] ^ temp[1];
        arr[n-1] = temp[n-2] ^ temp[n-1];
        
        for(int i=1; i<(n-1); ++i){
            arr[i] = temp[i-1] ^ temp[i+1];
        }
    }
};