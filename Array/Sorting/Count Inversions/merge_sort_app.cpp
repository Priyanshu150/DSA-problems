#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*log(n))
//Space complexity :- O(n) 

// Approach :-
// while doing the merge sort, when we are merging the sub-region 
// until left sub-region element are smaller then it's has no inversion 
// but for right sub-region has smaller element then 
// for all the element present in left region can be considered as inversion 

//link :- https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution {
  private:
    int merge(int left, int mid, int right, vector<int> &arr){
        int lp = left, rp = mid+1, cnt = 0;
        vector<int> temp;
        
        // traverse on the both sub-region parallely 
        while(lp <= mid && rp <= right){
            // add the number which is smaller in the temp array 
            if(arr[lp] <= arr[rp]){
                temp.push_back(arr[lp]);
                lp++;
            }
            else{
                // count of inversion will be all the number on left partion 
                // for which the right number is smaller
                cnt += (mid-lp+1);
                temp.push_back(arr[rp]);
                rp++;
            }
        }
        // add the remaining element if it's left out in any of the partition 
        while(lp <= mid){
            temp.push_back(arr[lp]);
            lp++;
        }
        
        while(rp <= right){
            temp.push_back(arr[rp]);
            rp++;
        }
        // update the given array with reference with temp array 
        for(int i=left; i<=right; ++i){
            arr[i] = temp[i-left];
        }
        
        return cnt;
    }
  
    int mergeSort(int left, int right, vector<int> &arr){
        if(left >= right)
            return 0;
        
        int cnt = 0;
        int mid = left + (right - left) / 2;
        // split the array in smaller chunks which are sorted 
        cnt += mergeSort(left, mid, arr);
        cnt += mergeSort(mid+1, right, arr);
        // merge the seprated part and count the inversion 
        cnt += merge(left, mid, right, arr);
        
        return cnt;
    }
  
  public:
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        // use merge sort to find the inversion count 
        return mergeSort(0, n-1, arr);
    }
};