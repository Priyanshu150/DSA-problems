#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N)    

//Approach :-
// Caluculate the prefix sum considering 1 as +1 and 0 as -1
// While calulating the sum save the sum which is occuring first time into the map with its index
// If any sum happens to occur again that means the sum for a subarray is 0 which means equal num of ones and zeros are present
// Calulate the length based on the index of the prev same sum if occured

//link :- https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n = arr.size(), res = 0, sum = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        
        for(int i=0; i<n; ++i){
            if(arr[i])      sum += 1;
            else            sum -= 1;
            
            if(mp.count(sum))
                res = max(res, i - mp[sum]);
            else
                mp[sum] = i;
        }
        return res;
    }
};