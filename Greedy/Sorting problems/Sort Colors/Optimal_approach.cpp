#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// put there pointer low, mid and high 
// [0 to low-1] will be the region of 0
// [low to mid-1] will be the region of 1
// [mid to high] will be unknow region
// [high to n] will be regino of 2 
// traversing in the unknown region from mid to high and put it to the respective region
// if we encounter 0, then swap mid with low and low will increase as the region expand 
// and mid will also increase as we're moving to next pointer
// if we encounter 1, then we'll increase mid ptr expanding the 1 region
// if we encounter 2, then we'll swap mid with high ptr value 
// and decrement high value dentoting expanding 2 region and increment mid 



//Link :- https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                ++low;
                ++mid;
            }
            else if(nums[mid] == 1){
                ++mid;
            }
            else{
                swap(nums[mid], nums[high]);
                --high;
            }
        }
    }
};