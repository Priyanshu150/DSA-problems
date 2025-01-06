#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int size = 1e5+2;
        vector<bool> freq(size, false);
        
        for(auto num: arr)
            freq[num] = true;
        
        int res = 0, lcs = 0, prev = -2;
        
        for(int i=0; i<size; ++i){
            if(freq[i]){
                if(prev+1 == i)
                    lcs++;
                else
                    lcs = 1;
                
                prev = i;
            }
            res = max(res, lcs);
        }
        return res;
    }
};