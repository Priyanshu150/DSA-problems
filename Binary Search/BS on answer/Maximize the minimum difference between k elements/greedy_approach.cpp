#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*log(n))
//Space complexity :- O(n)

// Approach :-   
// answer will be possible b/w a certain range i.e [0, max_ele - min_ele]
// hence we can apply binary serach on the answer 
// In order to check wheather a particular difference for k element is possible or not 
// we'll sort the whole array and considering arr[0] as our first element 
// we'll find the next element which has difference greater than give difference 
// and considering this element as previous we'll find the next one, 
// also we'll count the elemnent we've accumulate so far with the particular difference 
// If that is greater or equal to k it's possible otherwise it's not

//link :- https://www.geeksforgeeks.org/problems/maximize-the-minimum-difference-between-k-elements/1

class Solution {
  private:
    bool isPossible(int diff, vector<int> &arr, int &k, int &n){
        int cnt = 1, prev = arr[0];
        
        for(int i=1; i<n; ++i){
            if((arr[i] - prev) >= diff){
                cnt++;
                prev = arr[i];
            }
            if(cnt >= k)
                return true;
        }
        return false;
    }
  
  public:
    int maxMinDiff(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size(), low = 1, high = arr[n-1] - arr[0], res = 0;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, arr, k, n)){
                res = mid;
                low = mid+1;
            }
            else    high = mid-1;
        }
        return res;
    }
};
