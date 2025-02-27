#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*N*N)
// Space complexity :- O(N)

// Approach :-
// Consider every pair of starting index (i, j) and find the next sum arr[i] + arr[j]
// If sum exist on right side, move the pointer and repeat the process
// Calulate the length simulatenously and main the maximum length


// Link :- https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), res = 0;
        unordered_set<int> st(arr.begin(), arr.end());

        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                int prev = arr[i], curr = arr[j], sum = prev + curr, len = 2;

                while(st.count(sum)){
                    res = max(res, ++len);
                    prev = curr;
                    curr = sum;
                    sum = prev + sum;
                }
            }
        }
        return res;
    }
};