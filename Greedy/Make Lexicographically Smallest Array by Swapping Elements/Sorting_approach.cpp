#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n*2)

// Approach :- 
// We can create a group/component for all the element which can be swap under the limit
// Within the group we can swap all the element in any configuration to get lexiographically smallest 
// [10, 11, 8] with limit = 2, can form a grp because (10 - 8) < limit and (11 - 10) < limit even thought (11 - 8) > limit
// we can convert it to lexiographically smallest by swaping any number of times to [8, 10, 11]
// Best way to form such group is sorting 
// Traversing left to right if nums[ind] - nums[ind - 1] > limit that means both are from diffent grp
// Create a copy array with index and sort the array, index will help us to swap element in original array
// Traverse the copy list in grp and store the index of a grp
// Sort the index of grp and then put the value from copy on the sorted index of the original array
// Both copy and index are sorted so at sorted index we will have least value 
// Follow techDose youTube video for more details 

//Link :- https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> copy;

        for(int i=0; i<n; ++i)
            copy.push_back({nums[i], i});
        
        sort(copy.begin(), copy.end());

        int l = 0, r = 1;
        while(r < n){
            vector<int> indices;

            while(r<n && (copy[r].first - copy[r-1].first) <= limit){
                indices.push_back(copy[r].second);
                ++r;
            }
            indices.push_back(copy[l].second);
            sort(indices.begin(), indices.end());
            int ind = 0;

            while(l<r){
                nums[indices[ind]] = copy[l].first;
                ind++;
                l++;
            }
            r++;
        }
        return nums;
    }
};