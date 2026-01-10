#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// count the number of subarray having the count of odd number equal to at most k and k-1
// the difference b/w the two will give us extactly k subarrys 
// for solving this, use standard sliding window approach 
// and maintain a sliding window of valid odd number count 

//link :- https://www.geeksforgeeks.org/problems/count-subarray-with-k-odds/1

class Solution {
  private:
    int atMostK(vector<int>& arr, int k, int &n){
        int left = 0, odd = 0, res = 0;
        
        for(int right=0; right<n; ++right){
            // count the odd numbers
            if(arr[right] & 1){
                odd++;
            }
            
            // maintain a sliding window 
            while(odd > k){
                // decrement the odd numbers while shrinking the window 
                if(arr[left] & 1){
                    odd--;
                }
                ++left;
            }
            // add the number of subarray into answer 
            res += (right - left + 1);
        }
        return res;
    }
  
  public:
    int countSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        // give the subarry for exactly k distinct values 
        return atMostK(arr, k, n) - atMostK(arr, k-1, n);
    }
};