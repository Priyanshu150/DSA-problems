#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*N)
//Space complexity :- O(1) 

// Approach :-
// Whenever we find a 0 in the array we flip the next k bit using for loop
// if we are not able to find next k bit then return -1
// otherwise count the number of steps for the same 

//link :- https://www.geeksforgeeks.org/problems/minimum-number-of-k-consecutive-bit-flips--171650/1

class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), res = 0;
        
        for(int i=0; i<n; ++i){
            if(arr[i] == 0){
                if(n-i < k)
                    return -1;
                
                for(int j=i; j<(i+k); ++j){
                    arr[j] = !arr[j];
                }
                res++;
            }
        }
        return res;
    }
};
