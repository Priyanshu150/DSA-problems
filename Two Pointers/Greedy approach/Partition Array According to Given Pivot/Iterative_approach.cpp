#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N)

// Approach :- 
// Traverse left to right, first time push all the element that is smaller pivot 
// at the same time cnt the number of element equal to pivot and second time push cnt number of times pivot element into arr
// third time push element which are greater than pivot into the array


//Link :- https://leetcode.com/problems/partition-array-according-to-given-pivot/

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