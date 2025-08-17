#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// use merge sort, change the merge function to handle the case


//Link :- https://www.geeksforgeeks.org/problems/sort-by-absolute-difference-1587115621/1

class Solution {
  private:
    void merge(int left, int mid, int right, vector<int> &arr, int &x){
        vector<int> temp;
        int i = left, j = mid+1;
        
        while(i<=mid && j<=right){
            if(abs(x - arr[i]) <= abs(x - arr[j])){
                temp.push_back(arr[i]);
                ++i;
            }
            else{
                temp.push_back(arr[j]);
                ++j;
            }
        }
        while(i<=mid){
            temp.push_back(arr[i]);
            ++i;
        }
        while(j<=right){
            temp.push_back(arr[j]);
            ++j;
        }
        
        for(int ind=left; ind<=right; ++ind)
            arr[ind] = temp[ind - left];
    }
    
    void mergeSort(int left, int right, vector<int> &arr, int &x){
        if(left < right){
            int mid = (left + right)/2;
            mergeSort(left, mid, arr, x);
            mergeSort(mid+1, right, arr, x);
            merge(left, mid, right, arr, x);
        }
    }
    
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        int n = arr.size();
        return mergeSort(0, n-1, arr, x);
    }
};