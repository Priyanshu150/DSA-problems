#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(sum_of_array))  
// Space complexity :- O(1)

// Approach :-  
// search on the answer range to find the min answer possible, use binary search
// the starting / lowest value will the maximum element of the array 
// and the ending / highest value will be the sum of all the elements
// for a give sum check wheather it's possible to attain the min sum or not 
// traverse on the array maintain a sum if currVal is greater than fixed_sum then it'll not be possible
// if sum + currVal >= fixed_sum then change the subarray and update the sum with currVal
// otherwise add currVal to the sum
// atlast if the cnt <= k that means it's possible otherwise it's not 


// Link(gfg) :- https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1
// Link(leetcode) :- https://leetcode.com/problems/split-array-largest-sum/

class Solution {
  private:
    bool isPossible(int maxSum, vector<int> &arr, int &k, int &n){
        int sum = 0, cnt = 1;
        
        for(int i=0; i<n; ++i){
            if(arr[i] > maxSum)     return false;
            else if(arr[i]+sum > maxSum){
                sum = arr[i];
                cnt++;
            }
            else    sum += arr[i];
        }
        return cnt <= k;
    }
  
  public:
    int splitArray(vector<int>& arr, int k) {
        // code here
        int res = 0, n = arr.size();
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), high);
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(isPossible(mid, arr, k, n)){
                res = mid;
                high = mid-1;
            }
            else    low = mid+1;
        }
        return res;
    }
};
