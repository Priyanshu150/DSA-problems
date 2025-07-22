#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*word_length)
// Space complexity :- O(N)

// Approach :-
// Hash all the folders value using hash set
// start traversing on each folder and then char by char traverse on the folder 
// check on the hash set if we found the current directory, check only at '/' when name of direcotry is completed 
// if we found it skip those otherwise add them to our answers


// Link :- https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

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