#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(m*log(n*m))  
// Space complexity :- O(1)

// Approach :-  
// since the value will be fixed we can find the answer using binary search
// the lowest value will be 1 and highest will be n*m respectively
// for any number find the how many number are less than or equal to that number
// if the count of those is greater than or equal to k then, high = mid-1 to decrease count
// else low = mid+1 to increase count
// for count the number less than a particular number 
// traverse on each row and use the formula and accumulate the count accros rows, min(m, val/rowNo)
// where rowNo is 1 to m 


// Link :- 
// (gfg) https://www.geeksforgeeks.org/problems/kth-smallest-number-in-multiplication-table/1
// (leetcodee) https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/

class Solution {
  private:
    int findCount(int val, int &m, int &n){
        int cnt = 0;
        
        for(int row=1; row<=m; ++row){
            cnt += min(n, val/row);
        }
        return cnt;
    }
  
 
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
        int low = 1, high = m*n, res = 0;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(findCount(mid, m, n) >= k){
                high = mid-1;
                res = mid;
            }
            else    low = mid+1;
        }
        return res;
    }
};


