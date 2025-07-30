#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*k)
//Space complexity :- O(n)

// Approach :-
// store each file directory in hash set 
// traverse in the list of directories, for each directory traverse it from the scratch 
// and build that in a string, check wheather that string/directory already existed or not
// if it does then don't include that in answer otherwise include them

//Link :- https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st;

        for(auto file: folder){
            st.insert(file);
        }
        vector<string> ans;

        for(auto file: folder){
            int n = file.size();
            string str = "";
            bool flag = true;

            for(int i=0; i<n-1; ++i){
                if(file[i] == '/' && st.count(str)){
                    flag = false;
                    break;
                }
                str += file[i];
            }
            if(flag)    ans.push_back(file);
        }
        return ans;
    }
};