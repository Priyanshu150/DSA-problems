#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(M + N)       // Where m is length of shift array and n is length of string s
//Space complexity :- O(N)          // for prefix sum array

//Approach
// Find the prefix sum based on the index given in the shift array
// Prefix sum array represent the for each char how many shifts it has to go through
// Calculate the final outcome of char based on the final number of shift it has to go through

class Solution {
private:
    char replaceChar(char ch, int num){
        int currNum = ch - 'a';

        if(currNum + num > 25){
            num = (currNum + num) - 26;
            return char('a' + num);
        }
        if(currNum + num < 0){
            num = (currNum + num + 1);
            return char('z' + num);
        }
        return char(ch + num);
    }
    int rem(int num){
        int isNeg = 1;
        if(num < 0){
            isNeg = -1;
            num *= -1;
        }
        return (num % 26) * (isNeg);
    }

public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size(), sum = 0;
        vector<int> prefix(n, 0);

        for(auto shift: shifts){
            int lt = shift[0], rt = shift[1], dir = shift[2];
            if(dir == 1){
                prefix[lt] += 1;
                if(rt+1 < n)        prefix[rt+1] -= 1;
            }
            else{
                prefix[lt] -= 1;
                if(rt+1 < n)        prefix[rt+1] += 1;
            }
        }
        string res = "";

        for(int i=0; i<n; ++i){
            sum += prefix[i];
            sum = rem(sum);
            res += replaceChar(s[i], sum);
        }
        return res;
    }
};