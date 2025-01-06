#include<bits/stdc++.h>
using namespace std;

//Link(leetcode) :- https://leetcode.com/problems/shifting-letters-ii/description/

//Time complexity :- O(M + N)       // Where m is length of shift array and n is length of string s
//Space complexity :- O(N+1)       // for prefix sum array

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size(), sum = 0;
        vector<int> prefix(n+1, 0);

        for(auto shift: shifts){
            int lt = shift[0], rt = shift[1], dir = shift[2];
            if(dir == 1){
                prefix[lt] += 1;
                prefix[rt+1] -= 1;
            }
            else{
                prefix[lt] -= 1;
                prefix[rt+1] += 1;
            }
        }
        string res = "";

        for(int i=0; i<n; ++i){
            sum = (sum + prefix[i]) % 26;
            if(sum < 0)
                sum += 26;

            res += char(97 + (s[i]-'a'+sum)%26);
        }
        return res;
    }
};