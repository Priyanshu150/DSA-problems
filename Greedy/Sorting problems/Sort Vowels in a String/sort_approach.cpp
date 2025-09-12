#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*log(n))
// Space Complexity: O(n*log(n))

// Approach :- 
// take all the vowel in temprorary string and sort it
// and put this sorted string on the the final string where vowels are present 


// Link :- https://leetcode.com/problems/sort-vowels-in-a-string/

class Solution {
public:
    string sortVowels(string s) {
        int sz = s.size();
        string res(sz, ' '), lower = "", upper = "";

        for(int i=0; i<sz; ++i){
            if(s[i]=='A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                upper += s[i];
            else if(s[i]=='a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                lower += s[i];
            else
                res[i] = s[i];
        }
        sort(begin(lower), end(lower));
        sort(begin(upper), end(upper));
        int j(0), k(0), n = upper.size(), m = lower.size();

        for(int i=0; i<sz; ++i){
            if(res[i] == ' '){
                if(j<n)         res[i] = upper[j++];
                else if(k<m)    res[i] = lower[k++];
            }
        }
        return res;
    }
};