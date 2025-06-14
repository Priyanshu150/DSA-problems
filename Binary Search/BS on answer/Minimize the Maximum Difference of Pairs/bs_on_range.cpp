#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(max_diff))
// Space complexity :- O(1)

// Approach :- 
// for minimum difference among the pair the number should be as closest as possible 
// hence the array should be sorted 
// the minimum diff among pairs can be 0 
// the maximum diff among pairs can be difference b/w maximum element and minimum element 
// we can search on the range from low to high, we'll use binary search for the same
// for a particular difference we'll calculate that how many pairs are possible 
// where the difference b/w the pairs should be less than or equal to given difference value 

// Link :- https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/

class Solution {
private:
    bool isPossible(int diff, int &p, vector<int> &nums, int &n){
        int cnt=0, i=0;

        while(i<n-1){
            if(nums[i+1] - nums[i] <= diff){
                cnt++;
                i+=2;
            }
            else
                i++;
        }
        return cnt>=p;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int low = 0, high = nums[n-1] - nums[0], res=0;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(mid, p, nums, n)){
                res = mid;
                high = mid-1;
            }
            else 
                low = mid+1;
        }
        return res;
    }
};