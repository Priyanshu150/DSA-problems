#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^3)
// Space Complexity: O(n)

// Approach :- 
// If we fix two pair of number we can easily find the 3rd number using a+b = c
// Let's fix a&b and for finding a store index with element in a hash map table
// as long we find the next number we can increase the length of that series and keep on looking further

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