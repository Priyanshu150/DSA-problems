#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(len(num))
// Space complexity :- O(1)

// Approach :-  
// traverse on the number by converting it in string form from left to right 
// and convert the first 6 to 9 and found the resultant number 

//Link :- https://leetcode.com/problems/maximum-69-number/

var maximum69Number  = function(num) {
    let res = 0;
    let flag = true;
    let str = num.toString();

    for(let digit of str){
        if(flag && digit === '6'){
            res = res*10 + 9;
            flag = false;
        }
        else        res = res*10 + Number(digit);
    }
    return res;
};