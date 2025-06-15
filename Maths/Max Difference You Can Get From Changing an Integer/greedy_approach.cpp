#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(len(num))
// Space complexity :- O(1)

// Approach :- 
// convert num into 2 strings and change the char accordingly 
// for the first number make it maximum, change the first non 9 number to 9 
// and all the subsequent occurence of the same number to 9
// for the second number make it minimum, if the number present at starting is not 1 
// then replace all the occurence of that number to 1
// otherwise change the occurence of other number after that which non-zero to 0
// and all the subsequent occurence of the same number to 0
// find the difference b/w max and min number to get our answer


// Link :- https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/

class Solution {
public:
    int maxDiff(int num) {
        string num1 = to_string(num);
        string num2 = to_string(num);
        int n = num1.size();

        if(n == 1)
            return 8;
        
        char ch1='#', ch2='#', replace;

        for(int i=0; i<n; ++i){
            if(ch1 == '#' && num1[i] != '9'){
                ch1 = num1[i];
            }
            if(ch2 == '#' && num1[i] != '1' && num1[i] != '0'){
                ch2 = num1[i];
                if(i == 0)  replace = '1';
                else        replace = '0';
            }
        }
        for(int i=0; i<n; ++i){
            if(ch1 == num1[i]){
                num1[i] = '9';
            }
            if(ch2 == num2[i]){
                num2[i] = replace;
            }
        }
        return stoi(num1) - stoi(num2);
    }
};