#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*N)
// Space complexity :- O(N*N)

// Approach :-
// For every index starting from 2, we will find the 2 element on the left side whose sum is equal to curr_element
// We can use two pointers to find the sum of pair 
// Once we find the pair we will calulate the max_len of the sequence 
// we using dp to update the length so that it can be accessed on further sequence 
// use 2d dp of length n*n to keep the index length of [start][end]


// Link :- https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), res = 0;
        vector<vector<int>> dp(n, vector<int> (n, 0));

        for(int curr=2; curr<n; ++curr){
            int start = 0, end = curr-1;
            while(start < end){
                int sum = arr[start] + arr[end];
                if(sum < arr[curr])
                    start++;
                else if(sum > arr[curr])
                    end--;
                else{
                    dp[end][curr] = 1 + dp[start][end];
                    res = max(res, dp[end][curr]);
                    start++;
                    end--;
                }
            }
        }
        return (res == 0) ? 0 : res+2;
    }
};