#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(1)

// Approach :-  
// The range of h-index can be b/w (1 - n), because at max we can have n count 
// we'll use binary serach on this range and try to maximize it 
// for every h-index we can count if it's possible 
// i.e whether the count of rankings in the array is more than or equal to the given h-index or not 


//Link :- https://www.geeksforgeeks.org/problems/find-h-index--165609/1

class Solution {
  private:
    bool isPossible(int val, vector<int> &citations, int &n){
        int cnt = 0;
        
        for(int i=0; i<n; ++i){
            // count the number of citation value having greater than mid 
            if(val <= citations[i])
                cnt++;
        }
        return val <= cnt;
    }
  
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size(), low = 0, high = n, res = 0;
        
        // standard bs on answer 
        while(low <= high){
            int mid = low + (high - low)/2;
            // check for current mid is possible to get at least mid citation value papers 
            if(isPossible(mid, citations, n)){
                res = mid;
                low = mid+1;            // maximize the value 
            }
            else    high = mid-1;       // minimize the value and find a valid one 
        }
        return res;
    }
};