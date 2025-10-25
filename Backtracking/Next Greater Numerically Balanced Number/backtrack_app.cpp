#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(9^d)
// Space complexity :- O(10)

// Approach :- 
// use backtrack to generate the smallest number
// maintain a freq array for the freq of all the digits 
// the state of recusion will be (curr_number_val, give_number, number_of_digit)
// loop on the digit from 1 to 10 and if it's possible or not 

//Link :- https://leetcode.com/problems/next-greater-numerically-balanced-number/

class Solution {
private:
    vector<int> freq = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int solve(int num, int &n, int digitLeft){
        if(digitLeft == 0){
            for(int digit=1; digit<10; ++digit){
                if(freq[digit] > 0 && freq[digit] != digit)
                    return 0;
            }
            
            return num > n ? num : 0;
        }
        int result = 0;

        for(int digit=1; digit<10; ++digit){
            if(freq[digit] > 0 && freq[digit] <= digitLeft){
                freq[digit] -= 1;
                result = solve(num*10 + digit, n, digitLeft-1);
                if(result != 0)     return result;
                freq[digit] += 1;
            }
        }
        return result;
    }

public:
    int nextBeautifulNumber(int n) {
        if(n == 0)      return 1;

        int digitLeft = to_string(n).size();
        int result = solve(0, n, digitLeft);
        if(result != 0)
            return result;
        
        return solve(0, n, digitLeft+1);
    }
};
