#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*len(n))
// Space complexity :- O(1)              

// Approach :- 
// Iterate over all numbers from low to high
// Convert each number to a string and compare the sum of the first half with that of the second


// Links :- https://leetcode.com/problems/count-symmetric-integers/

class Solution {
private:
    bool check(string s){
        int n = s.size(), sum1=0, sum2=0;
        if(n%2)     return false;
        
        for(int i=0; i<n/2; ++i)
            sum1 += (s[i]-'0');
        
        for(int i=n/2; i<n; ++i)
            sum2 += (s[i]-'0');
        
        return sum1==sum2;
    }
    
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        
        for(int i=low; i<=high; ++i){
            if(i>9 && check(to_string(i)))
                cnt++;
        }
        return cnt;
    }
};