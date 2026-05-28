#include<bits10_1.h>
using namespace std;

//Time complextiy :- O(n + m)
// Space complexity :- O(m)
// where n, m is total number of char in wordsContainer and wordQuery respectively 

// Approach :-  
// for seraching we can store all the word of wordsContainer in trie in reverse order
// for try we'll maitain a index which give us the smallest index suffix index amoung all the words 
// serach each wordQuery in reverse form in trie and update the index at every match we found 
// intitally update the root with the minimum length of words in wordContainer index 

// Link :-  https://leetcode.com/problems/longest-common-suffix-queries/

class TrieNode{
  private:
    int index;
    TrieNode* children[26];

  public:
    // constructor
    TrieNode(){
        index = -1;
        
        for(int i=0; i<26; ++i){
            children[i] = nullptr;
        }
    }

     ~TrieNode() {
        for (int i = 0; i < 26; ++i)
            delete children[i];   // recursively frees entire subtree
    }
    
    // check if the next node is present or not 
    bool isNotPresent(TrieNode* node, char ch){
        return (node -> children[ch - 'a'] == nullptr);
    }

    // create a node pointing to the certains char 
    void createNode(TrieNode* node, char ch){
        node -> children[ch - 'a'] = new TrieNode();
    }
    
    // find next node poniting to certain character 
    TrieNode* findNext(TrieNode* node, char ch){
        return node -> children[ch - 'a'];
    }
    
    // set the index value 
    void setIndex(int ind){
        index = ind;
    }

    // get the index value 
    int getIndex(){
        return index;
    }
};

class Solution {
private:
    void updateIndex(vector<string>& wordsContainer, int ind, TrieNode* node){
        // no index updated for the current word 
        if(node -> getIndex() == -1){
            node -> setIndex(ind);
        }else{
            int prevInd = node -> getIndex();
            // prev word greater than the current word, then update the index 
            if(wordsContainer[ind].size() < wordsContainer[prevInd].size()){
                node -> setIndex(ind);
            }
        }
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        // intitalize the root of the trie node 
        TrieNode* root = new TrieNode();

        for(int ind=0; ind<n; ++ind){
            // insert the current word from container into the trie
            TrieNode* node = root;
            int m = wordsContainer[ind].size();
            
            // insert the reverse form of string 
            for(int i=m-1; i>=0; --i){
                char ch = wordsContainer[ind][i];

                if(node -> isNotPresent(node, ch)){
                    node -> createNode(node, ch);
                }

                updateIndex(wordsContainer, ind, node);
                node = node -> findNext(node, ch);
            }
            updateIndex(wordsContainer, ind, node);
        }
        vector<int> ans;
        int q = wordsQuery.size();
        
        // find the suffix match of each string from wrod query 
        for(int ind=0; ind<q; ++ind){
            TrieNode* node = root;
            int m = wordsQuery[ind].size();
            int resInd = node -> getIndex();
            
            // search for each word 
            for(int i=m-1; i>=0; --i){
                char ch = wordsQuery[ind][i];

                if(node -> isNotPresent(node, ch)){
                    break;
                }
                
                node = node -> findNext(node, ch);
                // update the index with the highest suffix value 
                resInd = node -> getIndex(); 
            }
            ans.push_back(resInd);
        }
        // And at the end of stringIndices(), before return:
        delete root;
        return ans;
    }
};