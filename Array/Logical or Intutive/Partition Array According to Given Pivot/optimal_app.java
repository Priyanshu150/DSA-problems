import java.util.*

// Time complexity :- O(n+n)
// Space complexity :- O(n)

// Approach :- 
// count the number of element equal to or lesser than pivot 
// In answer array, lesser than pivot element will be in range (0 to lessEleCount - 1)
// equal element to pivot will be in range (lessEleCount to lessEleCount + countEqualEle - 1)
// greater than pivot element will be in range (lessEleCount + countEqualEle - 1 to n)
// update the element while traversing second time on its right place 

// Link :- https://leetcode.com/problems/partition-array-according-to-given-pivot/description/

class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        int lessEle = 0, equalEle = 0;

        for(int i=0; i<n; ++i){
            // count the number less than pivot element 
            if(nums[i] < pivot){
                lessEle++;
            }
            // count the number equal to pivot element 
            else if(nums[i] == pivot){
                equalEle++;
            }
        }
        int[] res = new int[n];

        int i=0, j = lessEle, k = (lessEle + equalEle);

        // place the element at the right place 
        for(int ind=0; ind<n; ++ind){
            if(nums[ind] < pivot){
                res[i] = nums[ind];
                ++i;
            }
            else if(nums[ind] == pivot){
                res[j] = nums[ind];
                ++j;
            }
            else{
                res[k] = nums[ind];
                ++k;
            }
        }
        return res;
    }
}