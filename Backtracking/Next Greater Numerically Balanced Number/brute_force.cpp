#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(larget_num * log10(num))
// Space complexity :- O(10)

// Approach :-  
// start a loop from next number given to max number 
// and check each number whichever is balanced 
// return that as our answer 

//Link :- https://leetcode.com/problems/next-greater-numerically-balanced-number/

class Solution {
private:
    bool isBalanced(int num){
        vector<int> freq(10, 0);

        while(num > 0){
            int ld = num%10;
            if(ld == 0)     return false;
            num /= 10;
            freq[ld] += 1;
        }

        for(int digit=1; digit<=9; digit++){
            if(freq[digit] == 0)
                continue;
            
            if(digit != freq[digit])
                return false;
        }
        return true;
    }

public:
    int nextBeautifulNumber(int n) {
        if(n == 0)
            return 1;

        for(int num=n+1; num<1224444; ++num){
            if(isBalanced(num)){
                return num;
            }
        }
        return 1224444;
    }
};