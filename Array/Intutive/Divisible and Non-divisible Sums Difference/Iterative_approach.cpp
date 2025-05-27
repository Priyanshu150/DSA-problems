#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)
// Space complexity :- O(1)              


// Links :- https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int nums1 = 0, nums2 = 0;

        for(int i=1; i<=n; ++i){
            if(i % m == 0)      nums2 += i;
            else                nums1 += i;
        }
        return (nums1 - nums2);
    }
};