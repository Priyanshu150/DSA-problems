#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// Find the dominant element element and cnt the the number of that in array
// Traverse from left to right, and cnt the dominant element on left and right 
// and check when the condition is meet then return the ind
// at last if we didn't find any index then return -1


//Link :- https://leetcode.com/problems/minimum-index-of-a-valid-split/

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size(), ele = 0, cnt = 0;

        for(int i=0; i<n; ++i){
            if(cnt == 0){
                ele = nums[i];
                cnt = 1;
            }
            else if(ele == nums[i])
                cnt++;
            else 
                cnt--;
        }
        cnt = 0;

        for(int i=0; i<n; ++i){
            if(ele == nums[i])
                cnt++;
        }
        int leftCnt = 0, rightCnt = cnt;
        
        for(int i=0; i<n-1; ++i){
            if(nums[i] == ele){
                leftCnt++;
                rightCnt--;
            }
            if(leftCnt > (i+1)/2 && rightCnt > (n-i-1)/2)
                return i;
        }
        return -1;
    }
};