#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(log(n1, n2))
//Space complexity :- O(1)

// Approach :-  
// use can use binary search based on the partition 
// the partion will either some element from nums1 and other element from nums2 to get exactly k elements 
// and rest elements keep it on the other side
// why k elements ? because we want to find the kth element without building the whole array 
// we'll use the same concept from median of k sorted array question
// here our low will be max(0, k-n2) and high will min(n1, k)
// whever we get a valid partition we can return max(l1, l2) to get kth element 


//link :- https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

class Solution {
  public:
    int kthElement(vector<int> &nums1, vector<int> &nums2, int k) {
        // code here
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2)     return kthElement(nums2, nums1, k);
        
        int len = n1+n2;
        int low = max(0, k-n2), high = min(n1, k);
        
        while(low <= high){
            int mid1 = low + (high - low)/2;
            int mid2 = k - mid1;
            
            int l1 = INT_MIN, r1 = INT_MAX;
            int l2 = INT_MIN, r2 = INT_MAX;
            
            if(mid1-1 >= 0)     l1 = nums1[mid1-1];
            if(mid2-1 >= 0)     l2 = nums2[mid2-1];
            if(mid1 < n1)       r1 = nums1[mid1];
            if(mid2 < n2)       r2 = nums2[mid2];
            
            if(l1 <= r2 && l2 <= r1)
                return max(l1, l2);
            else if(l1 > r2)
                high = mid1-1;
            else
                low = mid1+1;
        }
        return 0;
    }
};