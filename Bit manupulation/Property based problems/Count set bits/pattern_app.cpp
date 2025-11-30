#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(log(N))
// Space complexity :- O(1)

// Approach :-   
// If we observe the pattern we'll see the number repeats 0-1, 00-11, 000-111, 0000-1111 
// for each column level starting from right to left 
// we'll find the last set bit(msb) on the number (assume x is the bit number )
// set bit before that number will be (x * (2^(x-1)))
// count of msb will be (n-(2^x)+1)
// and for remaining number after msb we can again use recursion 
// the number  left will be (n-(2^x)
// total number set bit will be fullBits + msbBits + remainingBits;

//Link :- https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

// approach 1
int countSetBits(int n) {
    // Base case
    if (n == 0)
        return 0;

    // Find highest power of 2 less than or equal to n
    int x = log2(n);

    //Set bits in the full pattern 0 to (2^x - 1)
    int fullBits = x * (1 << (x - 1));

    //Contribution of the highest bit from 2^x to n
    int msbBits = n - (1 << x) + 1;

    //Recursively count remaining set bits after removing highest bit
    int remaining = n - (1 << x);
    int remainingBits = countSetBits(remaining);

    // Total set bits
    return fullBits + msbBits + remainingBits;
}

// approach 2 
class Solution {
  private:
    int msb(int num){
        int cnt = 0;
        
        while(num > 0){
            // left shift number by 1 
            num >>= 1;
            cnt++;
        }
        return cnt-1;
    }
  
  public:
    int countSetBits(int n) {
        // base case 
        if(n == 0)
            return 0;
        
        // most singnificant bit 
        int x = msb(n);
        // count of bits before 2^x
        int y = x * (1 << (x-1));
        // reamining number
        int z = n - (1 << x);
        return y + 1 + z + countSetBits(z);
    }
};
