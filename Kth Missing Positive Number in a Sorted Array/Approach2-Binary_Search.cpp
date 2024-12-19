#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        if(k < arr[0])      return k;
        int low = 0, high = arr.size()-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            int missing = abs(k - mid - 1);
            if(missing < k)     low = mid+1;
            else        high = mid-1;
        }
        int more = k - high - 1;
        return arr[high] + more;
    }
};