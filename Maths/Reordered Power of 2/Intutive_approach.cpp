#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(29 * 10(digit len))
// Space complexity :- O(1)

// Approach :-
// count the freq of each number in powerOf2s and give number 
// use vector to count the digit of each powerof2 number and check with the current number
// at max the digit that we can have is 10 hence the size of vector should be 10 

// Link :- https://leetcode.com/problems/reordered-power-of-2/

class Solution {
private:
    vector<int> countDigits(int num){
        vector<int> freq(10, 0);

        while(num > 0){
            freq[num % 10] += 1;
            num /= 10;
        }
        return freq;
    }

public:
    bool reorderedPowerOf2(int n) {
        vector<int> freq = countDigits(n);

        for(int i=0; i<=29; ++i){
            if(freq == countDigits(1 << i))
                return true;
        }
        return false;
    }
};