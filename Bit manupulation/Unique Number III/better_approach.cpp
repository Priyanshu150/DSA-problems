#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*32)
//Space complexity :- O(1)

// Approach :-
// for every bit index count the number of set bit in all the numbers of array 
// if the cnt is multiple of 3 that means that bit is not contributing to the number that is appearing once
// else it's appearing, use a result variable to add the bit index whose cnt is not divisble by 3
// for adding we can use | or ^
// ^ will work beause we are starting with 0 and no bit is set to repeat at a particular bit index


//link :- https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        // code here
        int n = arr.size(), res = 0;
        
        for(int bit=0; bit<32; ++bit){
            int cnt = 0;
            for(int i=0; i<n; ++i){
                if(arr[i] & (1 << bit))
                    cnt++;
            }
            res |= (cnt%3) ? (1<<bit) : 0;
            // res ^= (cnt%3) ? (1<<bit) : 0;       or use this 
        }
        return res;
    }
};

