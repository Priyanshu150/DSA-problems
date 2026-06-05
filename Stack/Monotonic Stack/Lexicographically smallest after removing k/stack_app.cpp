#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n + k)
// Space complexity :- O(n)

// Approach :- 
// we can update the value of k depending of the size of s 
// maintain a monotnic stack of char and pop the char for only 'k' times 
// remaining string will be our answer 

// Link :- https://www.geeksforgeeks.org/problems/lexicographically-smallest-after-removing-k/1

class Solution {
  private:
    bool isPowerOf2(int num){
        return (num & (num - 1)) == 0;
    }
  
  public:
    string lexicographicallySmallest(string &s, int k) {
        int n = s.size();
        
        // check if length is power of 2 or not 
        if(isPowerOf2(n)){
            k /= 2;     // divide k value by 2 
        }else{
            k *= 2;     // multiply k by 2
        }
        
        stack<char> st;
        
        for(auto ch: s){
            // maintain a montonic stack of char until we've k value 
            while(!st.empty() && k > 0 && (st.top()-'a') > (ch - 'a')){
                st.pop();
                k -= 1;
            }
            // add current char in stack 
            st.push(ch);
        }
        // remove remaining k char from the string 
        while(!st.empty() && k > 0){
            st.pop();
            k -= 1;
        }
        // check if string is empty 
        if(st.empty())         return "-1";
        
        string res = "";
        
        // form the string from remaining char 
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        // reverse the string to get answer due stack property 
        reverse(res.begin(), res.end());
        return res;
    }
};