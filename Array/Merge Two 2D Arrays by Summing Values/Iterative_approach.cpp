#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N+M)
//Space complexity :- O(1)    

//Approach :-
// Traverse both the array simultaneously and build the ans 
// if the key in num1 is smaller then add that to answer
// if the key in num2 is smaller then add that to answer
// otherwise add the sum these two value in both array with the key that they are sharing

//link :- https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int ind1 = 0, ind2 = 0, n = nums1.size(), m = nums2.size();

        while(ind1 < n && ind2 < m){
            if(nums1[ind1][0] < nums2[ind2][0]){
                ans.push_back(nums1[ind1]);
                ind1++;
            }
            else if(nums2[ind2][0] < nums1[ind1][0]){
                ans.push_back(nums2[ind2]);
                ind2++;
            }
            else{
                int key = nums1[ind1][0], val = nums1[ind1][1] + nums2[ind2][1];
                ans.push_back({key, val});
                ++ind1;
                ++ind2;
            }
        }
        while(ind1 < n){
            ans.push_back(nums1[ind1]);
            ind1++;
        }
        while(ind2 < m){
            ans.push_back(nums2[ind2]);
            ind2++;
        }
        return ans;
    }
};