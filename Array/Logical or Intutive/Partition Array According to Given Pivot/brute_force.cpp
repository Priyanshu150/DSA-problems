#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n+n+n)
// Space complexity :- O(n)

// Approach :- 
// add the less element in answer array followed by equal and larger element 

// Link :- https://leetcode.com/problems/partition-array-according-to-given-pivot/description/

class Solution {
public:
    vector<int> pivotArray(vector<int>& arr, int pivot) {
        int n = arr.size(), cnt = 0;
        vector<int> ans;

        for(int i=0; i<n; ++i){
            if(arr[i] < pivot)
                ans.push_back(arr[i]);
            else if(arr[i] == pivot)
                cnt++;
        }
        while(cnt--)
            ans.push_back(pivot);

        for(int i=0; i<n; ++i){
            if(arr[i]>pivot)
                ans.push_back(arr[i]);
        }
        return ans;
    }
};