#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(26)

// Approach :-  
// for storing every word we can use trie data structure implementation
// Trie data structrue is concept where dictionary type logic is implemented to store word
// It take constanct time and costly space

// insert() -> start from root node put every char into the childnode, if node doesn't exist create it
// search() -> start from root node check every char into the childnode, if char doesn't exist then word doesn't exist
//          -> at last check if the last node is mark as end node or not if yes then word exist 
// insert() -> start from root node check every char into the childnode, if char doesn't exist then prefix doesn't exist
//          -> at last return true because prefix will always be valid if we reach till last


// Link :- https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1

class TrieNode{
  public:
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode(){
        isEnd = false;
        for(int i=0; i<26; ++i)
            children[i] = nullptr;
    }
};


class Trie {
  private:
    TrieNode* root;
  
  public:
    Trie() {
        // implement Trie
        root = new TrieNode();
    }

    void insert(string &word) {
        // insert word into Trie
        TrieNode* node = root;
        int n = word.size();
        
        for(int i=0; i<n; ++i){
            if(node -> children[word[i] - 'a'] == nullptr)
                node -> children[word[i] - 'a'] = new TrieNode();
            
            node = node -> children[word[i] - 'a'];
        }
        node -> isEnd = true;
    }

    bool search(string &word) {
        // search word in the Trie
        TrieNode* node = root;
        int n = word.size();
        
        for(int i=0; i<n; ++i){
            if(node -> children[word[i] - 'a'] == nullptr)
                return false;
            
            node = node -> children[word[i] - 'a'];
        }
        return (node -> isEnd) ? true : false;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        TrieNode* node = root;
        int n = word.size();
        
        for(int i=0; i<n; ++i){
            if(node -> children[word[i] - 'a'] == nullptr)
                return false;
            
            node = node -> children[word[i] - 'a'];
        }
        return true;
    }
};