#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(1)

//Approach :- 
// for power of 5, pre-calculate all the number which are power of 5 and less that 1e9
// using recusion try to split the array and generate the length of split
// take minimum length out of all the split
// use for loop in recursion to find a valid split of string which is power of 5 and call reucursion further
// if no split is possible return -1 
// for calculating the binary string to decimal value we can use following approach, 
// 1) prevVal*2 + curr_bit 
// 2) prevVal << 1 + curr_bit (<< left shift )
// 3) traverse on the string and calculate the result based on the the digit found

//Link :- https://www.geeksforgeeks.org/problems/cutting-binary-string1342/1

class Solution {
  private:
    unordered_set<int> st;
  
    void powerof5(){
        int num = 1;
        while(num < 1e9){
            st.insert(num);
            num *= 5;
        }
    }
  
    int solve(int ind, string &s, int &n){
        if(ind == n)
            return 0;
        
        int res = 1e8, val = 0;
        
        for(int i=ind; i<n; ++i){
            val = (val<<1) + (s[i] - '0');
            // or use this formula
            // val = (val*2) + (s[i] - '0');
            if(s[ind] != '0' && st.count(val)){
                res = min(res, 1+solve(i+1, s, n));
            }
        }
        return res;
    }
 
  public:
    int cuts(string s) {
        // code here
        int n = s.size();
        powerof5();
        int res = solve(0, s, n);
        return (res == 1e8) ? -1 : res;
    }
};


class Solution {
  private:
    unordered_set<int> st;
  
    void powerof5(){
        int num = 1;
        while(num < 1e9){
            st.insert(num);
            num *= 5;
        }
    }
  
    int decimalValue(int ind, int i, string &s){
        if(s[ind] == '0')   return -2;
        int val = 0, len = i-ind;
        
        for(int j=ind; j<=i; ++j){
            if(s[j] == '1')
                val += (1 << len);
            
            len--;
        }
        return val;
    }
  
    int solve(int ind, string &s, int &n){
        if(ind == n)
            return 0;
        
        int res = 1e8;
        
        for(int i=ind; i<n; ++i){
            int val = decimalValue(ind, i, s);
            if(st.count(val)){
                res = min(res, 1+solve(i+1, s, n));
            }
        }
        return res;
    }
 
  public:
    int cuts(string s) {
        // code here
        int n = s.size();
        powerof5();
        int res = solve(0, s, n);
        return (res == 1e8) ? -1 : res;
    }
};