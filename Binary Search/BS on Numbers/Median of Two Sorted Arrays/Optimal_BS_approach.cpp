#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(log(min(n, m)))  
// Space complexity :- O(1)

// Approach :- 
// The median of an array lies in the middle, either 2 or 1 element depending on the count 
// We can divide the array in two parts and then taking the median
// the number of element on each side will be (len(nums1) + len(nums2) + 1)/2 [len]
// for a valid split some number should be coming from nums1 or nums2 
// for choosing the number we can use binary search 
// we'll take 0 to len(nums1) number from nums1 and left of the number from nums2 
// so low can be 0 and high = len(nums1), using standard binary search 
// mid will give the number at middle, we'll calculate the middle for both the array 
// and we'll ponit l1, l2, r1, r2 to middle and middle-1 index of both the array
// if l1 <= r2 and l2 <= r1, that means its a valid split calculate the median 
// if even then, ((double)(max(l1,l2)) + min(r1, r2))/2.0
// other for odd, max(l1, l2);
// if l1 > r2, then we need to decrease number from first array so, high = mid-1
// otherwise we've to increase the number heance low = mid+
// try applying binary search on the sorter array 

// Link :- https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2)        return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = n1, left = (n1+n2+1)/2, n = n1+n2;

        while(low <= high){
            int mid1 = low + (high - low)/2;
            int mid2 = (left - mid1);
            int l1 = INT_MIN, l2 = INT_MIN;
            int r2 = INT_MAX, r1 = INT_MAX;

            if(mid1 < n1)   r1 = nums1[mid1];
            if(mid2 < n2)   r2 = nums2[mid2];
            if(mid1-1 >= 0)     l1 = nums1[mid1-1];
            if(mid2-1 >= 0)     l2 = nums2[mid2-1];

            if(l1 <= r2 && l2 <= r1){
                if(n%2 == 1)        return max(l1, l2);
                return ((double)(max(l1,l2)) + min(r1, r2))/2.0;
            }
            else if(l1 > r2)    high = mid1-1;
            else                low = mid1+1;
        }
        return 0;
    }
};
