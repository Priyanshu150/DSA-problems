#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2^n)
// Space complexity :- O(n)

// Approach :-   
// there are total n-1 ways to pick the first number 
// and after that for choosing other there will be 2 possibilities of subproblem 
// 1st case the number swap it will i-th possition and left number will be n-2
// 2nd case the i-th position number will have to be place at different position 
// hence the formula becomes => f(n) = (n-1)*[f(n-1) + f(n-2)]

// Link :- https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1

class Solution {
  private:
    int solve(int num){
        if(num <= 3)
            return (num-1);
        
        return (num-1) * (solve(num-1) + solve(num-2));
    }
  
  public:
    int derangeCount(int n) {
        return solve(n);
    }
};