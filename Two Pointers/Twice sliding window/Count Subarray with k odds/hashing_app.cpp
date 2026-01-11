#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(n)

// Approach :-
// using hashing approach, we can count the freq of odd number along the array 
// and for every element, we'll count the how many freq (odd-k) exists 

//link :- https://www.geeksforgeeks.org/problems/count-subarray-with-k-odds/1

class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        int n = arr.size(), count = 0, odd = 0;
        
        unordered_map<int,int> prefix;     // {odd_num_cnt, freq}
        prefix[0]= 1;                      // 0 will have 1 as a count 
        
        for(int i=0; i<n; ++i){
            // count the odd number 
            if(arr[i] % 2)
                odd++;
            
            // check if previously we've seen (odd - k)
            if(prefix.count(odd - k) != 0)
                count += prefix[odd - k];
            
            // odd number count update 
            prefix[odd]++;
        }
        return count;
    }
};