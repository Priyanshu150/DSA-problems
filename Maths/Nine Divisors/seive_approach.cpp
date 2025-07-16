#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(log(n))
//Space complexity :- O(1)

// Approach :-
// if we observe the pattern of the number which has 9 divisors we'll find a^2 + b^2 or a^8
// so we need to find the prime number (a and b) such that they less than n
// we'll find the prime number using seive method where maximum limit will be sqrt(n)
// and traverse on each pair of these prime number to get the count of number which satisfies the eqn

//Link :- https://www.geeksforgeeks.org/problems/nine-divisors3751/1

class Solution {
  public:
    int countNumbers(int n) {
        // Code Here
        int range = sqrt(n);
        vector<bool> seive(range+1, 1);
        
        // find the prime number till the range of sqrt(n)
        for(int i=2; i*i<=range; ++i){
            if(seive[i]){
                for(int j=i*i; j<=range; j+=i){
                    seive[j] = 0;
                }
            }
        }
        int res = 0;
        // Look for the prime numbers which satisfies the equation a^2 + b^2 <= n
        for(int i=2; i<=range; ++i){
            if(seive[i]){
                if(pow(i, 8) <= n)    res += 1;
                for(int j=i+1; j<=range; ++j){
                    if(seive[j]){
                        if(pow(i, 2)*pow(j, 2) <= n)
                            res += 1;
                    }
                }
            }
        }
        return res;
    }
};