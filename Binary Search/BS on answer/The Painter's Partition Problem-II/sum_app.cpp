#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(sum))
// Space complexity :- O(1)

// Approach :-   
// the answer will lie for continuous value we have to pick the smallest value possible 
// we can use binary search on answer to find the min possible value 
// low value will be maximum value of array and highest value will be the sum of the array 
// find the current value it's possible for k painter to paint or not 
// try allocating continuous block to a painter until the time not exceeds the fixed one
// otherwise allocate new painter, if at last it's possible for k painter then it's valid 
// try to minimize for the time value if it's valid 
// otherwise increase it and find a valid value 

// Link :- https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

class Solution {
  private:
    bool isPossible(int t, vector<int> &arr, int &k){
        int painters = 1, currTime = 0;
        
        // traverse on each board time 
        for(auto board: arr){
            // allocate the continuous board to painter until it fall under t time
            if(currTime + board <= t){
                currTime += board;
            }
            // otherwise allocate it to next paointer 
            else{
                currTime = board;
                painters++;
            }
            // painter count increases than k then it's not possible
            if(painters > k)
                return false;
        }
        return true;
    }
  
  public:
    int minTime(vector<int>& arr, int k) {
        int low = 0, high = 0, res = 0;
        
        for(auto board: arr){
            // maximum element of the array 
            low = max(low, board);
            // sum of the array
            high += board;
        }
        
        // standard bs on answer 
        while(low <= high){
            int mid = low + (high - low)/2;
            
            // check if it's possible to paint with k painter within mid time 
            if(isPossible(mid, arr, k)){
                res = mid;
                high = mid-1;       // try to minimize the time 
            }
            else{
                low = mid+1;        // maximize the time to find a valid time 
            }
        }
        return res;
    }
};