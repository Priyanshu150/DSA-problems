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
    bool isPossible(int height, vector<int> &arr, int k, int &w){
        int n = arr.size(), sum = 0;
        vector<int> prefixSum(n+1, 0);
        
        for(int i=0; i<n; ++i){
            // calucalte the new height that has to be added to the next height
            sum += prefixSum[i];
            
            // find the current height and the diff we need to maintain the 
            // current height to the required height 
            int current_height = (arr[i] + sum);
            int diff = height - current_height;
            
            // the height can not be attained even after giving water for k days
            if(diff > k)
                return false;
            
            // curr_height is already greater 
            if(diff <= 0)
                continue;
            
            // apply pefix sum technique to update the height for next w subarray
            sum += diff;
            prefixSum[i] += diff;
            prefixSum[min(n, i+w)] -= diff;
            
            k -= diff;      // days decrease by the used ones
        }
        return true;
    }
  
  public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int low = INT_MAX, high = INT_MIN;
        
        // find the min and max value of array 
        for(auto height: arr){
            low = min(low, height);
            high = max(high, height);
        }
        
        high += k;
        int res = low;
        
        // standard bs on answer 
        while(low <= high){
            int mid = low + (high - low)/2;
            
            // check if it's possible to attain 'mid' height for all or not 
            if(isPossible(mid, arr, k, w)){
                res = mid;
                low = mid+1;        // maximize the height 
            }
            else{
                high = mid-1;       // minimize the height to find a valid one 
            }
        }
        return res;
    }
};