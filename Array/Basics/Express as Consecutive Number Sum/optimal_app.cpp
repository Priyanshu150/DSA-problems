#include <bits/stdc++.h>
using namespace std;

//Time complextiy :- O(1)
// Space complexity :- O(1)

// Approach :- 
// if the number is power of 2 then it cannot be expressed as power of 2 


// Link :-  https://www.geeksforgeeks.org/problems/consecutive-numbers-for-sum3132/1

class Solution {
    public boolean isSumOfConsecutive(int n) {
        // base case 
        if(n == 1)
            return false;
        
        // is power of 2 
        if((n & (n-1)) == 0)
            return false;
        
        return true;
    }
}