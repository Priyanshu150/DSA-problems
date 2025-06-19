#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(1)

// Approach :- 
// seprate the lowercase and uppercase characters and sort them seprately
// traverse the string and put the sorted string at place of repective uppercase and lowercase char

// Link :- https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1

class Solution {
  public:
    string caseSort(string& s) {
        // code here
        string lower = "", upper = "";
        for(auto ch: s){
            if(islower(ch))
                lower += ch;
            else 
                upper += ch;
        }
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());
        int i=0, j=0, n = s.size();
        
        for(int ind=0; ind<n; ++ind){
            if(islower(s[ind])){
                s[ind] = lower[i++];
            }
            else{
                s[ind] = upper[j++];
            }
        }
        return s;
    }
};