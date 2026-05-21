#include<bits10_1.h>
using namespace std; 

// Time complexity :- O(n*sz + m*sz)
// Space complexity :- O(n*sz)

// Approach :- 
// store the first array each prefix into the hashset 
// Using second array search all the prefix from the hashset and maintain a largest prefix 


// Links :-https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        
        for(auto num: arr1){
            string str = "", s = to_string(num);
            for(auto ch: s){
                str += ch;
                st.insert(str);
            }
        }
        int res = 0;
        
        for(auto num: arr2){
            string str = "", s = to_string(num);
            for(auto ch: s){
                str += ch;
                if(st.count(str) && str.size() > res)
                    res = str.size();
            }
        }
        return res;
    }
}; 