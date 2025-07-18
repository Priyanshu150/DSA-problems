#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(log(n))
//Space complexity :- O(1)

// Approach :-
// for k to divide the n!,the prime factor of k should exist in the primes factor of number in factorial
// find the prime factors of numbers in n! and store them in an map
// find the prime factors of the k and store it in a another map2
// Check the prime factors of k and their frequence and loop up in map1 if the exists
// if they does then divide both the frequencies to get the actual value 
// the min value among all the factors of k will give our answer 

//Link :- https://www.geeksforgeeks.org/problems/power-of-k-in-n-where-k-may-be-non-prime4206/1

class Solution {
  private:
    void primeFactor(int num, map<int,int> &factors){
        while(num % 2 == 0){
            factors[2] += 1;
            num /= 2;
        }
        
        for(int i=3; i*i <= num; i+=2){
            while(num % i == 0){
                factors[i] += 1;
                num /= i;
            }
        }
        if(num > 2)
            factors[num] += 1;
    }
  
  public:
    int maxKPower(int n, int k) {
        // code here
        map<int, int> factorsOfNum, factorsOfK; 
        primeFactor(k, factorsOfK);
        
        for(int num=2; num<=n; ++num)
            primeFactor(num, factorsOfNum);
        
        int ans = INT_MAX;
        for(auto it: factorsOfK){
            ans = min(ans, factorsOfNum[it.first] / it.second);
        }
        return ans;
    }
};