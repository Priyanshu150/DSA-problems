#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(m*log(n*m))
// Space complexity :- O(1)

// Approach :- 
// the range will be 1 from n*m 
// for any number find what is the number of numbers less than that number
// if cnt < k, then low = mid+1, increasing the answer
// otherwise finding a valid range put high = mid-1

// Link :- https://www.geeksforgeeks.org/problems/kth-smallest-number-in-multiplication-table/1

class Solution {
  private:
    int lessThanK(int num, int m, int n){
        int res = 0;
        
        for(int i=1; i<=m; ++i){
            res += min(n, num/i);
        }
        return res;
    }
    
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
        int low = 1, high = m*n; 
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(lessThanK(mid, m, n) < k)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
};
