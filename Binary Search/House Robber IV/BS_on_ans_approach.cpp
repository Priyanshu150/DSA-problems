#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))  
// Space complexity :- O(1)

// Approach :- 
// we will use binary search to find the minimum value of a non-contiguous subsequence of a given size k
// Initialize the search range with the minimum and maximum elements of the input array
// Use a check function to determine if it is possible to select k non-consecutive elements that are less than or equal to the current "guess" value
// Adjust the search range based on the outcome of the check function, until the range converges and the minimum value is found


// Link :- https://leetcode.com/problems/house-robber-iv/

class Solution {
private:
    bool isPossible(int cap, vector<int>& nums, int &minHouseRobbed){
        int houseRobbed = 0, n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] <= cap){
                houseRobbed++;
                i++;
            }
            if(houseRobbed == minHouseRobbed)
                return true;
        }
        return false;
    }

public:
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, nums, k))
                high = mid-1;
            else    low = mid+1;
        }
        return low;
    }
};