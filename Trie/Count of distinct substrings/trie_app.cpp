#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(N^2)
// Space complexity :- O(N)

// Approach :-   
// generate all the substring using two for loop 
// save all the string in the trie 
// every time we're creating a new link, that gives us a new sub-array count those 


//Link :- https://www.geeksforgeeks.org/problems/count-of-distinct-substrings/1

class TrieNode{
  private:
    TrieNode* child[26];

  public:
    TrieNode(){
        for(int i=0; i<26; ++i){
            child[i] = nullptr;
        }
    }
    
    bool containLink(TrieNode* node, char ch){
        return (node -> child[ch - 'a'] != nullptr);
    }
    
    void createLink(TrieNode* node, char ch){
        node -> child[ch - 'a'] = new TrieNode();
    }
    
    TrieNode* nextLink(TrieNode* node, char ch){
        return node -> child[ch - 'a'];
    }
};

class Solution {
  public:
    int countSubs(string& s) {
        int n = s.size(), res = 0;
        TrieNode* root = new TrieNode();
        
        // generate every possible substring 
        for(int i=0; i<n; ++i){
            TrieNode* temp = root;
            for(int j=i; j<n; ++j){
                
                if(!temp -> containLink(temp, s[j])){
                    temp -> createLink(temp, s[j]);
                    res += 1;
                }
                
                temp = temp -> nextLink(temp, s[j]);
            }
        }
        return res;
    }
};