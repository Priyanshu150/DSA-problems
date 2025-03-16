#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(1)

// Approach :- 
// we can use greedy approach to count the number of jumps that is needed to reach end
// at each jump we'll store the maxJump we can to take from that index
// maxJump can be caluclated as max value of arr[i]+i
// if we find the maxJump to be 0 then we can't reach the end 
// count the jumps that we've take that can be our answer 

// Link :- https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int ind = 0, n = arr.size(), jumps = arr[0], cnt = 0;
        
        while(ind < n){
            int maxJump = 0, newInd = 0;
            ++cnt;
            
            for(int i=ind+1; i<=ind+jumps; ++i){
                if(i == n-1)
                    return cnt;
                
                if(i+arr[i] > newInd+maxJump){
                    newInd = i;
                    maxJump = arr[i];
                }
            }
            if(maxJump == 0)
                return -1;
            
            ind = newInd;
            jumps = maxJump;
        }
        return cnt;
    }
};

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        if(arr[0] == 0)     return -1;
        
        int n = arr.size(), res = 0, left = 0, right = 0;
        
        while(right<n-1){
            int farthest = 0;
            for(int ind=left; ind<=right; ++ind)
                farthest = max(farthest, arr[ind]+ind);
            
            if(farthest == 0)       return -1;
            left = right+1;
            right = farthest;
            ++res;
        }
        return res;
    }
};