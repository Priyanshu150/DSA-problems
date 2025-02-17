#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n) + k)
// Space complexity :- O(n)

// Approach :-  
// Sort the array in descending order and take the largest k elements from the starting

// Link :- https://www.geeksforgeeks.org/problems/k-largest-elements4206/1

class Solution {
    public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        vector<int> ans;
        sort(arr.begin(), arr.end(), greater<int>());
        
        for(int i=0; i<k; ++i)
            ans.push_back(arr[i]);
        
        return ans;
    }
};