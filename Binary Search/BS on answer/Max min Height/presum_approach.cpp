#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(max_ele - min_ele))  
// Space complexity :- O(n)

// Approach :-  
// the answer will lie in certain range, hence we can apply binary search 
// the lowest value will be the min element of the array 
// the highest value will be the max element + K(number of days)
// for a particular height check wheater is possible to attain min height within k day or not 
// for checking traverse on the array and calculate the current height with fixed height 
// if it is less then grow them using k days
// also use prefix sum method to keep track of which flower height increases 
// because we've to increase next w flower also 
// use prefix sum and curr_height of flower to calculate the overall height of flower 

// Link :- https://www.geeksforgeeks.org/problems/max-min-height--170647/1

class Solution {
  private:
    bool isPossible(int height, vector<int> &arr, int k, int w){
        int n = arr.size(), preSum = 0;
        vector<int> temp(n+1, 0);
        
        for(int i=0; i<n; ++i){
            preSum += temp[i];
            
            if(arr[i] + preSum < height){
                int diff = height - arr[i] - preSum;
                if(diff > k)    return false;
                
                k -= diff;
                temp[min(i+w, n)] -= diff;
                preSum += diff;
            }
        }
        return true;
    }
  
  public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        int low = INT_MAX, high = INT_MIN, res = 0;
        
        for(auto num: arr){
            low = min(low, num);
            high = max(high, num+k);
        }
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, arr, k, w))      low = mid+1;
            else    high = mid-1;
        }
        return high;
    }
};