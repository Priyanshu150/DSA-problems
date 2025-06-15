#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(max_ele))
// Space complexity :- O(1)

// Approach :- 
// Try to find the sum of quotient for every number in the range 
// the lowest will 1 and highest will be maximum element of array 
// we can use binary search on the range and check wheather it satisfies the condition 


// Link :- https://www.geeksforgeeks.org/problems/smallest-divisor/1

class Solution {
  private:
    bool isPossible(int ele, vector<int> &arr, int &k, int &n){
        int sum = 0;
        
        for(int i=0; i<n; ++i){
            int quo = arr[i]/ele, rem = arr[i]%ele;
            sum += quo;
            sum += (rem>0) ? 1 : 0;
        }
        return sum <= k;
    }
  
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int n = arr.size(), low = 1, high, res;
        high = *max_element(arr.begin(), arr.end());
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, arr, k, n)){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
};