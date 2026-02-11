#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N^2)
// Space complexity :- O(1)

// Approach :-  
// if we find each cost of converting the height we'get a graph 
// which will be in V shape, first decreasing and then increasing 
// we've to find the v point i.e. the point where it's the minimum 
// we'll use binary search to search on potential answer i.e heights 
// find the min and max height which will be our range of search 
// and using curr_height find the cost, repeat same for curr_height-1 & curr_height+1
// compare all the 3 cost for curr_height, curr_height-1, curr_height+1
// which will tell us on which curve we're currently, increase, decreasing or the v point 
// if on increasing curve, eliminate the left half and move right i.e. low = mid+1
// if on decreasing curve, eliminate the right half and move left i.e high = mid-1
// if on the v-point, then that itself will be our answer 


// Link :- https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1

class Solution {
  private:
    int findCost(vector<int> &heights, vector<int> &cost, int h){
        int res = 0, n = heights.size();
        // cost to convert all building to h height 
        for(int i=0; i<n; ++i){
            res += cost[i] * abs(heights[i] - h);
        }
        return res;
    }
  
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        
        // find min and max height
        int mini = INT_MAX, maxi = INT_MIN;
        for(auto val: heights){
            mini = min(mini, val);
            maxi = max(maxi, val);
        }
        
        int low = mini, high = maxi, ans;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            // find cost of mid-1, mid and mid+1 to compare 
            int val1 = findCost(heights, cost, mid-1);
            int val2 = findCost(heights, cost, mid);
            int val3 = findCost(heights, cost, mid+1);
            
            // if mid gives lowest cost 
            if(val2 <= val1 && val2 <= val3){
                ans = val2;
                break;
            }
            // if decreasing side gives less cost 
            else if(val1 >= val2 && val2 >= val3){
                low = mid+1;
            }
            // if increasing side give less count 
            else if(val2 >= val1 && val3 >= val2){
                high = mid-1;
            }
        }
        return ans;
    }
};
