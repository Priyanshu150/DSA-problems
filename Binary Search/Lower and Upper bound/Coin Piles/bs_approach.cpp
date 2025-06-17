#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(1)

// Approach :- 
// sort the array and traverse on the each element and 
// find the first element index which is greater than curr_ele + k
// from that position to end find the sum of element 
// the expected sum will be number of element out range multiplied by curr_ele + k
// the difference b/w those 2 sum will give us the result that how many coins should be removed 
// one edge case will be if ind>0 all the element occuring before the current_element should be make as 0
// that can done by adding sum of previous elements to the coins removed 


// Link :- https://www.geeksforgeeks.org/problems/coin-piles5152/1

class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), sum = 0, res = INT_MAX;
        sort(arr.begin(), arr.end());
        vector<int> preSum(n+1, 0);
        
        for(int i=0; i<n; ++i){
            sum += arr[i];
            preSum[i+1] = sum;
        }
        
        for(int i=0; i<n; ++i){
            int pos = upper_bound(arr.begin()+i, arr.end(), arr[i]+k) - arr.begin();
            int expectedSum = (n - pos)*(arr[i]+k);
            int actualSum = (preSum[n] - preSum[pos]);
            res = min(res, actualSum - expectedSum + preSum[i]);
        }
        return res;
    }
};