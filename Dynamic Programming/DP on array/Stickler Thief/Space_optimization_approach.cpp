#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// We can further optimize the solution at we only need two next index from current one
// we can maintain two variable to keep track of the same 
// the possiblities remains same from tabulation

//link :- https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size(), ahead = 0, ahead1 = 0;
        
        for(int ind=n-1; ind>=0; --ind){
            int curr = max(ahead, arr[ind]+ahead1);
            ahead1 = ahead;
            ahead = curr;
        }
        return max(ahead, ahead1);
    }
};