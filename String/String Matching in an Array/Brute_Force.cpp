#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(sz*sz*m*n)   
//Space complexity :- O(1)

//Link :- https://leetcode.com/problems/string-matching-in-an-array/description/

class Solution {
private:
    bool isSubstring(string s1, string s2, int n, int m){
        int i = 0;

        while(i<=(m - n)){
            string str = s2.substr(i, n);
            if(str == s1)
                return true;
            
            i++;
        }
        return false;
    }

public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int sz = words.size();

        for(int i=0; i<sz; ++i){
            int n = words[i].size();
            for(int j=0; j<sz; ++j){
                if(i != j){
                    int m = words[j].size();
                    if(m <= n)     continue;
                    if(isSubstring(words[i], words[j], n, m)){
                        ans.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};