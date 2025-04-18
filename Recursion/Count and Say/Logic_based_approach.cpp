#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*maxLen_of_res)
// Space complexity :- O(1)

// Approach :-  
// Implement the rum length encoding using looping 
// apply recusion for caluclation the answer of number provided 
// base case will be when n == 1, then return 1

// Link :- https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int num) {
        if(num == 1)      return "1";

        string str = countAndSay(num-1), res = "";
        int cnt = 1, n = str.size();
        char ch = str[0];

        for(int i=1; i<n; ++i){
            if(ch != str[i]){
                res += (to_string(cnt) + ch);
                ch = str[i];
                cnt = 1;
            }
            else        cnt++;
        }
        res += (to_string(cnt) + ch);
        return res;
    }
};