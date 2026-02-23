#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*k)
//Space complexity :- O(N)

//Approach :-
// find the integer value of each subarray of size k using bit manipulation 
// store each value into hashset
// after adding all value if the size of set is exactly 2^k then all binary code of size k are present 

// Link :- https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/

class Solution {
private:
    int calcNum(int l, int r, string &s){
        int num = 0, bit = 0;
        // traverse from right to left and add each contribution of bit to form the number 
        for(int i=r; i>=l; --i){ 
            if(s[i] == '1'){
                num |= (1 << bit);
            }
            ++bit;
        }
        return num;
    }

public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> st;
        int n = s.size(), left = 1;
        // base case 
        if(k > n)   return 0;

        // (0, k-1) will be the first number, add into hash set 
        st.insert(calcNum(0, k-1, s));

        // traverse on the fixed length sliding window 
        for(int right=k; right<n; ++right){
            // caululate the number and add into hashset 
            int num = calcNum(left, right, s);
            st.insert(num);
            // move the window 
            ++left;
        }
        // at last size of set equal to 2^k, then it's has all possible substring otherwise not 
        return (st.size() == (1<<k));
    }
};