#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(1)

// Approach :-  
// If we find the pattern among the sequence we'll get a forumula
// i.e 2*prev_answer + fibonacci number of current number 


// links :- https://www.geeksforgeeks.org/problems/trail-of-ones3242/1

class Solution {
  public:
    int countConsec(int n) {
        // code here
        int prev = 0, prev1 = 1, res = 0;
        
        for(int i=1; i<n; ++i){
            int curr = prev + prev1;
            res = 2*res + curr;
            prev1 = prev;
            prev = curr;
        }
        return res;
    }
};