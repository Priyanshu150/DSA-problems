#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*L)
// Space complexity :- O(N*L)

// Approach :-  
// store every word in a hash set 
// traverse on every word of the string and check if all the prefix exist for that string or not 
// if it does then maintain longest and lexiographically smallest if equal length among them


// links :- https://www.geeksforgeeks.org/problems/find-the-longest-string--170645/1

class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
        string res = "";
        unordered_set<string> st;
        
        for(auto word: words)
            st.insert(word);
        
        for(auto word: words){
            string temp = "";
            bool isPresent = true;
            
            for(int i=0; i<word.size(); ++i){
                temp += word[i];
                if(!st.count(temp)){
                    isPresent = false;
                    break;
                }
            }
            if(isPresent){
                if(res.size() < temp.size())
                    res = temp;
                else if(res.size() == temp.size() && temp < res)
                    res = temp;
            }
        }
        return res;
    }
};