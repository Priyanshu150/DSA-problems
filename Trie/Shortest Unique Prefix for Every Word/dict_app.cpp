#include<bits/stdc++.h>
using namespace std; 

// Time complexity :- O(n*m)
// Space complexity :- O(26*26)

// Approach :- 
// store every word into trie and for ever char count the number of time it's appearing 
// traverse on the each string while maintain the prefix from starting 
// which every char is present only 1 time that is unique 
// otherwise whole string is prefix which will be default answer 


// Links :- https://www.geeksforgeeks.org/problems/shortest-unique-prefix-for-every-word/1

class Trie {
  private:
    int count;
    Trie* children[26];

  public:
  // contructor 
    Trie() {
        count = 0;      // initialize the initial count to 0
        
        // intialize all the child with null 
        for(int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
    
    // check if next node is present or not 
    bool isPresent(char ch) {
        return (children[ch - 'a'] != nullptr);
    }
    
    // create a new node 
    void createNode(char ch) {
        children[ch - 'a'] = new Trie();
    }

    // find the address of next node 
    Trie* findNext(char ch) {
        return children[ch - 'a'];
    }

    int getCnt() {
        return count;
    }

    void incCnt() {    
        count += 1;
    }
};

class Solution {
  public:
    vector<string> findPrefixes(vector<string>& arr) {
        Trie* root = new Trie();
        
        // add every node into the trie dict 
        for(auto word : arr) {
            int n = word.size();
            Trie* node = root;
            
            // traverse on every char on word 
            for(int ind = 0; ind < n; ++ind) {
                char ch = word[ind];
            
                // check if the node is present or not 
                if(!node->isPresent(ch)) {
                     // make new node if not present 
                    node->createNode(ch);
                }
                // move to the next node 
                node = node->findNext(ch);
                // increment the count of every char in node 
                node->incCnt();
            }
        }

        vector<string> res;
        
        // traverse on every char on word 
        for(auto word : arr) {
            int n = word.size();
            string str = "";
            Trie* node = root;
            
            // traverse on every char on word  
            for(int ind = 0; ind < n; ++ind) {
                char ch = word[ind];
                str += ch;          // add the current char into prefix
                node = node->findNext(ch);      // move to the corrent node
                
                // if the count is only 1, then that's a unique prefix 
                if(node->getCnt() == 1) {
                    break;
                }
            }
            res.push_back(str);
        }
        return res;
    }
};