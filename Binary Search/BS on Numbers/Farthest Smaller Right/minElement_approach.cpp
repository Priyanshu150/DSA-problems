#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*log(n))
//Space complexity :- O(n)

// Approach :-  
// Maintian a smallest element array that maintains from the left of current element which are all the smallest one 
// For every index using binary search we can find the max index which is at the last 
// till the index where smaller element are present from current element


//link :- https://www.geeksforgeeks.org/problems/farthest-smaller-right/1

class Solution {
  private:
    int search(int low, int high, int ele, vector<int> &minEle){
        int res = -1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(minEle[mid] < ele){
                res = mid;
                low = mid+1;
            }
            else    high = mid-1;
        }
        return res;
    }
  
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n = arr.size(), mini = INT_MAX;
        vector<int> minEle(n), ans(n);
        
        for(int i=n-1; i>=0; --i){
            mini = min(mini, arr[i]);
            minEle[i] = mini;
        }
        
        for(int i=0; i<n; ++i){
            int ind = search(i+1, n-1, arr[i], minEle);
            ans[i] = ind;
        }
        return ans;
    }
};