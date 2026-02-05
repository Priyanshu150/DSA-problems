#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n^2)   
//Space complexity :- O(n)

// Approach :- 
// re-iterate the multiplication process which we used in maths 
// keep track of every number multiplication in an array to remove the addition step of all numbers

//Link :- https://leetcode.com/problems/multiply-strings/description/

class Solution {
public:
    string multiply(string s1, string s2) {
        // base case 
        if(s1=="0" || s2=="0")      return "0";

        int l1 = s1.size(), l2 = s2.size();
        vector<int> ans(l1+l2, 0);      // create an array to store the answer 
       
        int i = l2-1;
        int pf = 0;
        
        // traverse on each char of s2 string 
        while(i>=0){
            int ival = s2[i]-'0';
            i--;
           
            int j=l1-1;
            int k = l1+l2-1-pf;
            int carry = 0;
           
            // traverse on each char of s1 string 
            while(j>=0 || carry!=0){
               int jval = j>=0 ? s1[j]-'0' : 0;
               j--;
               // caluclate the product by fixing char i of s2 and moving to all the char of s1
               int prod = ival*jval + carry + ans[k];
               // add the answer in the index 
               ans[k] = prod%10;
               // update the carry depending on the prod for next step 
               carry = prod/10;
               k--;
            }
            // increase the power factor as it change on every level of multiplication of digit 
            ++pf;
        }
        
        string res = "";
        for(auto it: ans){
            // skip the start numbers which we didn't update as part of our product operation 
            if(it==0 && res=="")    continue;
            // update the answer by converting it into string 
            res += to_string(it);
        }
        return res;
    }
};