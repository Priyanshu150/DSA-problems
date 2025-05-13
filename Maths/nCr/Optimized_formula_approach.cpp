#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(1)

// Approach :- 
// nCr is equal to n! / ((n-r)! * r!)
// expanding the formula we'll get n * (n-1) * .... / r * (r-1) * (r-2) * ......
// the number of time n will in numerator while be same nmber of times r will be in denominatro
// using these forumula calcula the result by applying the loop of r 


// Link :- https://www.geeksforgeeks.org/problems/ncr1019/1

class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        if(r > n)   return 0;
        if(r == n)  return 1;
        
        long long res = 1;
        
        for(int i=0; i<r; ++i){
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
};