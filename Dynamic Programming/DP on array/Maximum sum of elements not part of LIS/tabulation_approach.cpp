#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*N)  
// Space complexity :- O(N)

// Approach :-
// use tabulation approach of LIS, maintain 2 array for maximum len and sum till that index
// for every current index check all the previous index whose value is less that curr_ind
// and the 1+len[prev_ind] >= len[curr_ind], if found the update the len and sum till that index
// maintain a maxLen for the sequence 
// at last using the seqSum and maxLen, check all the subarray with minimum sum 
// and subtract it from the sum of array to get the final sum as needed


// Link :- https://www.geeksforgeeks.org/problems/maximum-sum-of-elements-not-part-of-lis/1

class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size(), totalSum = 0, maxLen = 1, res = 0;
        vector<int> len(n, 1), seqSum(n, 0);
        totalSum = accumulate(arr.begin(), arr.end(), totalSum);
        
        for(int i=0; i<n; ++i){
            seqSum[i] = arr[i];
            for(int j=0; j<i; ++j){
                if(arr[j] < arr[i] && len[i] <= 1+len[j]){
                    len[i] = 1+len[j];
                    seqSum[i] = seqSum[j] + arr[i];
                    maxLen = max(maxLen, len[i]);
                }
            }
        }
        for(int i=0; i<n; ++i){
            if(maxLen == len[i]){
                res = max(res, totalSum - seqSum[i]);
            }
        }
        return res;
    }
};