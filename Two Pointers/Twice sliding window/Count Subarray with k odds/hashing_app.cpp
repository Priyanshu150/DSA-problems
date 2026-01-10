#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(n)

// Approach :-
// 

//link :- https://www.geeksforgeeks.org/problems/count-subarray-with-k-odds/1

class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        int n = arr.size(), count = 0, odd = 0;
        
        unordered_map<int,int> prefix;
        prefix[0]= 1;
        
        for(int i=0; i<n; ++i){
            if(arr[i] % 2)
                odd++;
            
            if(prefix.count(odd - k) != 0)
                count += prefix[odd - k];
            
            prefix[odd]++;
        }
        return count;
    }
};