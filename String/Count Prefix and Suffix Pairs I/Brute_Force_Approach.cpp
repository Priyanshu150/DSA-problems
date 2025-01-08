#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*N*K)  
//Space complexity :- O(1)    

//Links :- https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description

class Solution {
private:
    bool isPrefixAndSuffix(string str1, string str2){
        int n = str1.size(), m = str2.size();
        if(n > m)           return false;
        if(str1 == str2)    return true;
        
        bool flag = true;
        
        if(str2.substr(0, n) != str1)       flag = false;
        if(str2.substr(m-n) != str1)        flag = false;
        
        return flag;
    }
    
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), res = 0;
        
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(isPrefixAndSuffix(words[i], words[j]))
                    res += 1;
            }
        }
        return res;
    }
};