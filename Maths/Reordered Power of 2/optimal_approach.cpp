#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(29 * 10(digit len))  
// Space complexity :- O(1)

// Approach :-
// count the freq of each number in powerOf2s and give number 
// instead of taking any extra space we calculate the sumation of each number frequency and form a new number 
// last digit of every number we're raising it to power of 10 and then adding to a sum(0)
// that we maintain frequency of each number in terms of power of 10 
// and later checking that number with our given number if it matching then we're goood 


// Link :- https://leetcode.com/problems/reordered-power-of-2/

class Solution {
private:
    int countDigits(int num){
        int sum = 0;

        while(num > 0){
            sum += pow(10, num % 10);
            num /= 10;
        }
        return sum;
    }

public:
    bool reorderedPowerOf2(int n) {
        int sum = countDigits(n);

        for(int i=0; i<=29; ++i){
            if(sum == countDigits(1 << i))
                return true;
        }
        return false;
    }
};