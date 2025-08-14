#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// use custom merging logic to count the number of pair
// while merging left and right side of the array 
// count the number each element in left side how many are 2*arr[j] val is smaller 
// since both are sorted we can move j once and can optimize the algorithm to use (n + n) complexity


//Link :- https://www.geeksforgeeks.org/problems/count-reverse-pairs/1

class Solution {
  private:
    int merge(int left, int mid, int right, vector<int> &arr){
        int cnt = 0, j = mid+1, i;
        
        while(i<=mid){
            if(j == right || arr[i] <= 2*arr[j]){
                cnt += (j - mid - 1);
                i++;
            }
            else    j++;
        }
        
        vector<int> temp;
        i = left, j = mid+1;
        
        while(i <= mid && j <= right){
            if(arr[i] <= arr[j])
                temp.push_back(arr[i++]);
            else 
                temp.push_back(arr[j++]);
        }
        while(i<=mid)   temp.push_back(arr[i++]);
        while(j<=right) temp.push_back(arr[j++]);
        
        for(int ind=left; ind<=right; ++ind)
            arr[ind] = temp[ind - left];    
        
        return cnt;
    }
    
    int mergeSort(int left, int right, vector<int> &arr){
        if(left >= right)
            return 0;
        
            int mid = (left + right)/2;
            int inv = mergeSort(left, mid, arr);
            inv += mergeSort(mid+1, right, arr);
            inv += merge(left, mid, right, arr);
            return inv;
    }
  
    
  public:
    int countRevPairs(vector<int> &arr) {
        // Code here
        int n = arr.size();
        return mergeSort(0, n-1, arr);
    }
};
