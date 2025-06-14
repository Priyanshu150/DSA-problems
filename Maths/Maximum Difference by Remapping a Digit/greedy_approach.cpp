#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n - len of num in string form)
// Space complexity :- O(1)

// Approach :-  
// remap the first non-nine digit to 9 to obtain the maximum number
// remap the first non-zero digit to 0 to obtain the minimum number


// Link :- https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/

class Solution {
public:
    int minMaxDifference(int num) {
        string num1 = to_string(num);
        string num2 = to_string(num);
        int n = num1.size();
        char ch1, ch2 = num2[0];
        
        for(int i=0; i<n; ++i){
            if(num1[i] != '9'){
                ch1 = num1[i];
                break;
            }
        }
        for(int i=0; i<n; ++i){
            if(num1[i] == ch1){
                num1[i] = '9';
            }
            if(num2[i] == ch2){
                num2[i] = '0';
            }
        }
        return stoi(num1) - stoi(num2);
    }
};