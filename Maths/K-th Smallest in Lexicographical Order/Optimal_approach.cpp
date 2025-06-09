#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(log N with base 10)
// Space complexity :- O(1)

// Approach :-  
// Calulate all the substring start from a particular two consecutive numbers 
// ex :- 1 & 2 (diff :- 1), 10 & 20 (diff :- 10), 100 & 200 (diff :- 100), 1000 (assuming out of bound)
// total number starting 1 will be 111, if k is less than 111 then it'll be from 1 
// otherwise we've to explore other substring, k -= 111 and now we'll explore 2 & 3
// otherwise if it's starting with 1 multiply number by 10 and repeat the same process 
// now we'll explore 10 & 11 and so on until k becomes 0


// Link :- https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/

class Solution {
private:
    #define ll long long

    int countSteps(int n, ll num1, ll num2){
        int steps = 0;

        while(num1 <= n){
            steps += min((ll)n+1, num2) - num1;  //n+1: to include Nth value in range count
            num1 *= 10;  // next level
            num2 *= 10;  // next level
        }
        return steps;
    }

public:
    int findKthNumber(int n, int k) {
        int curr = 1;    // current number 
        k -= 1;          // skip the 1st number i.e. 1

        while(k > 0){
            int steps = countSteps(n, curr, curr+1);
            if(steps <= k){
                k -= steps;     // skip the number which will never be kth smallest
                curr++;
            }
            else{
                curr *= 10;
                k--;            // current element has to be counted out
            }
        }
        return curr;
    }
};