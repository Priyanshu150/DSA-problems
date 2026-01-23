#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*N)
// Space complexity :- O(N)

// Approach :-  
// find the minimum sum index merge them delete one of the element from the array 
// and repeat the process untill we find the array is sorted 

// links :- https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/

class Solution {
private:
    int minPairSum(vector<int> &nums){
        int minSum = INT_MAX, index = -1;

        for(int i=1; i<nums.size(); ++i){
            // find the sum at current index 
            int sum = nums[i] + nums[i-1];

            // update the minimum sum 
            if(sum < minSum){
                minSum = sum;
                index = i-1;
            }
        }
        return index;
    }

public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        // check if the array is sorted or not 
        while(!is_sorted(nums.begin(), nums.end())){
            // find the index which contribute to minimum sum 
            int index = minPairSum(nums);
            // update the new sum 
            nums[index] = nums[index] + nums[index+1];
            // delete the next index from the array 
            nums.erase(nums.begin() + index + 1);
            operations++;
        }
        return operations;
    }
};