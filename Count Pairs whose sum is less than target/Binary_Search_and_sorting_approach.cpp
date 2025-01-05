#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*log(N) + N*log(N))
//Space complexity :- O(1)  

// User function Template for C++
class Solution {
  private:
    int binary_search(vector<int> &arr, int low, int high, int target){
        while(low <= high){
            int mid =  low + (high - low)/2;
            if(arr[mid] <= target) 
                low = mid+1;
            else
                high = mid-1;
        }
        return high;
    }
  
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        sort(arr.begin(), arr.end());
        int n = arr.size(), res = 0;
        
        for(int i=0; i<n-1; ++i){
            int ele = target - arr[i] - 1;
            int ind = binary_search(arr, i+1, n-1, ele);
            res += (ind - i);
        }
        return res;
    }
};