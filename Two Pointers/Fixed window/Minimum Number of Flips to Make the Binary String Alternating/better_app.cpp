#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(2*n)
//Space complexity :- O(2*n)

// Approach :-


//link :- https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        // add given string twice to eliminate traversing it in n^2
        string str = s+s;
        string s1 = "", s2 = "";

        // create both alternating string of size of 2*n 
        for(int i=0; i<2*n; ++i){
            if(i % 2 == 0){
                s1 += '0';
                s2 += '1';
            }else{
                s1 += '1';
                s2 += '0';
            }
        }

        int right = 0, cnt1 = 0, cnt2 = 0;
        // for first n size string find the count which are not matching 
        while(right < n){
            // compare it with type 1 i.e 0101....
            if(str[right] != s1[right]){
                cnt1++;
            }
            // compare it with type 2 i.e 1010....
            if(str[right] != s2[right]){
                cnt2++;
            }
            ++right;
        }
        // answer will be minimum of both 
        int res = min(cnt1, cnt2), left = 0;

        // maintain a sliding window of size n 
        while(right < 2*n){
            // compare it with type 1 i.e 0101....
            if(str[right] != s1[right]){
                cnt1++;
            }
            // compare it with type 2 i.e 1010....
            if(str[right] != s2[right]){
                cnt2++;
            }
            ++right;

            // decrement the count if conflicting bit is removed 
            if(str[left] != s1[left]){
                cnt1--;
            }
            if(str[left] != s2[left]){
                cnt2--;
            }
            ++left;

            // store minimum of all window 
            res = min({res, cnt1, cnt2});
        }
        return res;
    }
};