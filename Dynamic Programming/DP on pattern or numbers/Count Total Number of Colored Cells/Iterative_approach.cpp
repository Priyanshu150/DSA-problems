#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*log(N), N*sz*log(N) )  
// Space complexity :- O(N)

// Approach :-
// the nth number can be represented in the form of prev_num + 4*(num-1)

// Link :- https://leetcode.com/problems/count-total-number-of-colored-cells/

class Solution {
private:
    #define ll long long 

public:
    long long coloredCells(int n) {
        if(n == 1)  return 1;
        ll prev = 1;

        for(int i=1; i<n; ++i){
            ll curr = prev + 4*i;
            prev = curr;
        }
        return prev;
    }
};