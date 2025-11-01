#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(log(diff)*N*log(M))
//Space complexity :- O(1)

// Approach :-
// we can use binary search and decide on the partition based on the the fact that 
// how many number are smaller or equal to the mid value 
// our range of potential answer will be -1e10 to 1e10 according to constraints 
// use binary serach for count, traverse on the every element of one array
// and apply binary search on the second array count the number of element smaller or equal to (nums1[i]*nums2[mid])
// use two different binary search for possitive and negative array  
// we can decide that based on the fact nums1[i] is negative or not 


// link :- https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/

class Solution {
private:
    #define ll long long

    ll countSmallerOrEqual(ll num, vector<int>& nums1, vector<int>& nums2, int &n1, int &n2){
        ll productCnt = 0;

        for(int ind=0; ind<n1; ++ind){
            if(nums1[ind] >= 0){
                int low = 0, high = n2-1, m = -1;
                while(low <= high){
                    int mid = low + (high - low)/2;
                    ll product = 1LL* nums1[ind] * nums2[mid];

                    if(product <= num){
                        low = mid+1;
                        m = mid;
                    }
                    else                    high = mid-1;
                }
                productCnt += (m+1);
            }
            else{
                int low = 0, high = n2-1, m = n2;
                while(low <= high){
                    int mid = low + (high - low)/2;
                    ll product = 1LL * nums1[ind] * nums2[mid];

                    if(product <= num){
                        high = mid-1;
                        m = mid;
                    }
                    else                    low = mid+1;
                }
                productCnt += (n2 - m);
            }
        }
        return productCnt;
    }

public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size(), n2 = nums2.size();
        ll low = -1e10, high = 1e10, res;

        while(low <= high){
            ll mid = low + (high - low)/2;
            // check if this is kth smallest or not 
            ll cnt = countSmallerOrEqual(mid, nums1, nums2, n1, n2);
            if(cnt >= k){
                high = mid-1;
                res = mid;
            }
            else        low = mid+1;
        }
        return res;
    }
};