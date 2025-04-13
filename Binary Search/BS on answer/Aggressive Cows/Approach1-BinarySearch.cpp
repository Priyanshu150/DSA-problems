#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool isPossible(int dist, vector<int> &stalls, int k, int &n){
        int cows = 1, prevStallPos = stalls[0];
        
        for(int i=1; i<n; ++i){
            if(stalls[i] - prevStallPos >= dist){
                prevStallPos = stalls[i];
                cows++;
            }
            if(cows == k)
                return true;
        }
        return false;
    }
  
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // Write your code here
        int n = stalls.size(), low = 1, high, res=0;
        sort(stalls.begin(), stalls.end());
        high = stalls[n-1] - stalls[0];
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, stalls, k, n)){
                res = mid;
                low = mid+1;
            }
            else     high = mid-1;
        }
        return res;
    }
};