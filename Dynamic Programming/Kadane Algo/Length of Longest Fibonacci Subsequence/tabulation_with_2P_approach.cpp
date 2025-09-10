#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

// Approach :- 
// Using 2 pointer(2 sum) and dp concept 
// fixing two element and for finding the rest of element we use two sum technique 

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