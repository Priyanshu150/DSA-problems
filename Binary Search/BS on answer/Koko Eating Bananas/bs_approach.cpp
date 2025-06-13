#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*log(max_ele))
// Space complexity :- O(1)

// Approach :-  
// use a binary search approach to find the answer 
// the lowest banana per hour will 1 and highest will be maximum element of array 
// apply binary search on the range 
// traverse in the array and check for the a particular answer 
// wheather it'll be possible to complete within given hour


// Link :- https://www.geeksforgeeks.org/problems/koko-eating-bananas/1

class Solution {
  private:
    bool isPossible(int banana, vector<int> arr, int &n, int &k){
        int t = 0;
        
        for(int i=0; i<n; ++i){
            int quo = arr[i] / banana, rem = arr[i] % banana;
            t += quo;
            t += (rem > 0) ? 1 : 0;
            if(t > k)
                return false;
        }
        return t <= k;
    }
  
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low = 1, n = arr.size(), high, res;
        high = *max_element(arr.begin(), arr.end());
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, arr, n, k)){
                res = mid;
                high = mid-1;
            }
            else    low = mid+1;
        }
        return res;
    }
};