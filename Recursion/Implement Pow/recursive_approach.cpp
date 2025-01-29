#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(log(N))
// Space complexity :- O(1)

//Approach :- 
// Use recursion to solve it in log(n)
// If power is even, a^4 = a^2 * a^2 
// If power is odd, the a^5 = a^2 * a^2 * a
// base case will be when power = 0 or 1 then return 1 or a respectively
// For neg power, handle it seprately and return 1/res as res
// At every recursion step call, f(a, power/2)

//Link :- https://www.geeksforgeeks.org/problems/powx-n/1

class Solution {
  public:
    double power(double b, int e) {
        // code here
        //base case
        if(e == 0)      return 1.0;
        if(e == 1)      return b;
        
        //Handling negative number 
        bool isNeg = false;
        if(e < 0){
            isNeg = true;
            e *= -1;
        }
        
        // calculation of power
        double res = power(b, e/2);
        if(e%2 == 0)    res = res*res;
        else            res = (res*res*b);
        
        //final result calculation
        return (isNeg) ? 1/res : res;
    }
};