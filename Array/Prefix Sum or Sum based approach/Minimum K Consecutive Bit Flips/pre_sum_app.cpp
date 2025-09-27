#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N) 

// Approach :-
// We'll use prefix sum technique to elinate looping over next k bit 
// when sum is odd and curr_bit is 1 then we need to flip that bit 1 -> 0
// also when sum is even and curr_bit is 0 that means we need to flip the bit 0 -> 1
// otherwise we leave the bit as it is 
// for fliping we'll add a +1 to sum and -1 in prefix_array at curr_ind + k
// that way we can maintain flipping of bits without looping using prefix sum technique 
// if there are not sufficient number of bit in from of current invalid bit then it's not possible
// otherwise count the number of times we performed this operation that will be our answer 

//link :- https://www.geeksforgeeks.org/problems/minimum-number-of-k-consecutive-bit-flips--171650/1

class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), res = 0, sum = 0;
        vector<int> prefix(n+1, 0);
        
        for(int i=0; i<n; ++i){
            sum += prefix[i];
            
            if((arr[i] == 0 && sum%2 == 0) || (arr[i] == 1 && sum%2 == 1) ){
                if(n-i < k)
                    return -1;
                
                sum += 1;
                prefix[i+k] -= 1;
                res++;
            }
        }
        return res;
    }
};