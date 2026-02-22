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
        unordered_map<long, long> mp;
        // add 0 to hash map having contribution 1 
        mp[0] = 1;
        
        long xorr = 0, res = 0;
        
        for(auto num: arr){
            // find the overall xor till current index  
            xorr ^= num;
            // check (xorr ^ k), value exist or not 
            res += mp[xorr ^ k];        // add the contribution of that into answer 
            // update the contribution of current xor 
            mp[xorr] += 1;
        }
        return res;
    }
};