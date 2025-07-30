#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       //where n is the size of array of numbers
//Space complexity :- O(N)      // using map to store every combination of sum

//Note:- unordered_map take O(1) in searching 

//Approach :-
// Slinding window will not work because add an element into window might increase/ decrease / no change in xorr
// Using prefix sum approach calulating xorr for all window 
// Saving it in map for get the subarry with the value of (xorr ^ k)

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<long, long> mp;
        mp[0] = 1;
        
        long xorr = 0, res = 0;
        
        for(auto num: arr){
            xorr ^= num;
            res += mp[xorr ^ k];
            mp[xorr] += 1;
        }
        return res;
    }
};