#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(26)

// Approach :- 
// Maintain a freq array for uppercase and lowercase this will maintain the sorted order of chars
// traverse on the string and parallely on freq array of the repective char 
// at that index and update the value accordingly

// Link :- https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1

class Solution {
  public:
    string caseSort(string& s) {
        // code here
        vector<int> lower(26, 0), upper(26, 0);
        
        for(auto ch: s){
            if(ch>='a' && ch<='z'){
                lower[ch-'a'] += 1;
            }
            else{
                upper[ch-'A'] += 1;
            }
        }
        int l = 0, u = 0;
        string res = "";
        
        for(auto ch: s){
            if(ch>='a' && ch<='z'){
                while(lower[l] == 0)
                    ++l;
                
                res += ('a'+l);
                lower[l] -= 1;
            }
            else{
                while(upper[u] == 0)
                    u++;
                
                res += ('A'+u);
                upper[u] -= 1;
            }
        }
        return res;
    }
};