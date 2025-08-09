#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(1)  
// Space complexity :- O(1)

// Approach :-
// All the number that are power of 2 is in the format of either 0000...1...0000
// and n-1 should be in format of 0000...01111111...
// hence the & operation of both should be 0, if not that means it's not divisible by 2 

// Link :- https://leetcode.com/problems/power-of-two/

function isPowerOfTwo(n: number): boolean {
    if(n <= 0)      return false;
    return (n & n-1) == 0;
};