#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)
// Space complexity :- O(1)

// Approach :- 
// take '1' as -1 and '0' as +1 and find maximum subarray sum 
// use kadane algo to find maximum subarray sum 

// Link :- https://www.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1

class Solution {
  public:
    int maxSubstring(string &s) {
        int n = s.size();
        int res = INT_MIN;
        int sum = 0;
        
        // standard kadane algo 
        for(int i=0; i<n; ++i){
            // find the subarray sum 
            sum += ((s[i] == '0') ? 1 : -1);
           
            //maintain maximum subarray sum
            res = max(res, sum);
            
            if(sum < 0)
                sum = 0;
        }
        return res;
    }
};