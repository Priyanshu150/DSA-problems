#include<bits/stdc++.h>
using namespace std;


// Time complexity: O(nlogn)
// space complexity: O(n)

// Approach:
// make the group of every sorted number based on the limit 
// sort the array to bring element in limit as closest 
// use map to store the group number of every number in both direction 
// update the result array by taking the first element of the group and pop it from the list of that group

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        // create a temp array
        vector<int> vec = nums;
        // sort the temp array 
        sort(vec.begin(), vec.end());

        int groupNum = 0;
        // mapping to store number to group 
        unordered_map<int,int> numToGrp;
        numToGrp[vec[0]] = groupNum;        // add first number mapping

        // mapping to store group to number 
        unordered_map<int, list<int>> groupToList;
        groupToList[groupNum].push_back(vec[0]);        // add first number mapping
        
        for(int i=1; i<n; ++i){
            // check if continuous number are in given limit 
            if(abs(vec[i] - vec[i-1]) > limit){
                // update the group number 
                groupNum += 1;
            }
            // update the respective mapping 
            numToGrp[vec[i]] = groupNum;
            groupToList[groupNum].push_back(vec[i]);
        }

        vector<int> result(n);

        for(int i=0; i<n; ++i){
            // find the group number of current element 
            int group  = numToGrp[nums[i]];
            // find the first smallest number of that group
            result[i] = *groupToList[group].begin();
            // delete the first number of the group
            groupToList[group].pop_front();
        }
        return result;
    }
};