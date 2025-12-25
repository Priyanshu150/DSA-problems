#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*log(n))
//Space complexity :- O(1) 

// Approach :-
// we'll first find the pivot element index in the array 
// using that pivot element index, we'll call binary search twice to 
// count the number of less than the given target 

//link :- https://www.geeksforgeeks.org/problems/count-elements-less-than-or-equal-to-k-in-a-sorted-rotated-array/1

class Solution {
  private:
    int findPivot(vector<int> &arr, int &n){
        int low = 0, high = n-1;
        int minEle = INT_MAX, minInd = -1;
        
        // standard bs
        while(low <= high){
            int mid = low + (high - low)/2;
            
            // left part is sort
            if(arr[low] <= arr[mid]){
                // arr[low] will be smallest 
                if(arr[low] < minEle){
                    minEle = arr[low];
                    minInd = low;
                }
                // discard the left half
                low = mid+1;
            }
            // right part is sorted 
            else{
                // arr[mid] will be smallest 
                if(arr[mid] < minEle){
                    minEle = arr[mid];
                    minInd = mid;
                }
                // dicard the right half
                high = mid-1;
            }
        }
        return minInd;
    }
    
    int countNumberLessThanX(int left, int right, vector<int> &arr, int target){
        int low = left, high = right, ind = left-1;
        
        // standard bs 
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(arr[mid] <= target){
                ind = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return (ind-left+1);
    }
    
        
  public:
    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        // find the index having smallest value
        int pivotInd = findPivot(arr, n);
        
        // count the number of value less than x using bs 
        int count1 = countNumberLessThanX(0, pivotInd-1, arr, x);
        int count2 = countNumberLessThanX(pivotInd, n-1, arr, x);
        
        return (count1 + count2);
    }
};