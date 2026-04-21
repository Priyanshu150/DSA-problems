#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(m+n)
// Space complexity :- O(1)


// Link :- https://www.geeksforgeeks.org/problems/two-water-jug-problem3402/1

class Solution {
  private:
    int gcd(int a, int b){
        if(b == 0)
            return a;
        
        return gcd(b, a%b);
    }
    
    int pour(int fromCap, int toCap, int d){
        int from = fromCap, to = 0;
        
        // initial fill 
        int step = 1;
        
        while(from != d && to != d){
            int temp = min(from, toCap - to);
            
            to += temp;
            from -= temp;
            step++;
            
            if(from == d || to == d)
                break;
            
            // refil source 
            if(from == 0){
                from = fromCap;
                step++;
            }
            
            // empty destinatin 
            if(to == toCap){
                to = 0;
                step++;
            }
        }
        return step;
    }

  public:
    int minSteps(int m, int n, int d) {
        // to make sure that m is smaller than n 
        if(m > n)   swap(m,n);
        
        // if d>n, it is not possible to measure the water 
        if(d > n)       return -1;
        
        // if gcd of m and n does not divide d 
        // then solution is not possible 
        if(d % gcd(m, n) != 0)
            return -1;
        
        // try both direction and take minimum:
        // 1. Pour from n to m 
        // 2. Pour from m to n 
        return min(pour(n, m, d), pour(m, n, d));
    }
};