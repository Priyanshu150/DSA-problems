#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*32)
// Space complexity :- O(32)

// Approach :-  
// We'll insert the bit representation of each word into the trie 
// For finding the maxNumber, for a particular number we'll check each bit
// for each bit, check if opposite bit exist in trie, if it does consider that else otherwise 
// repeat this for each number in the array and keep track of maxNumber 


// links :- https://www.geeksforgeeks.org/problems/maximum-xor-of-two-numbers-in-an-array/1

struct TrieNode{
    TrieNode* links[2];
    
    bool containsKey(int bit){
        return (links[bit] != nullptr);
    }
    
    TrieNode* get(int bit){
        return links[bit];
    }
    
    void put(int bit, TrieNode* node){
        links[bit] = node;
    }
};

class Trie{
  private:
    TrieNode* root;
  
  public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(int num){
        TrieNode* node = root;
        
        for(int i=31; i>=0; --i){
            int bit = (num >> i) & 1;
            if(!node -> containsKey(bit))
                node -> put(bit, new TrieNode());
            
            node = node -> get(bit);
        }
    }
    
    int getMax(int num){
        int maxNum = 0;
        TrieNode* node = root;
        
        for(int i=31; i>=0; --i){
            int bit = (num >> i) & 1;
            if(node -> containsKey(1 - bit)){
                maxNum |= (1<<i);
                node = node -> get(1 - bit);
            }
            else 
                node = node -> get(bit);
        }
        return maxNum;
    }
};

class Solution {
  public:
    int maxXor(vector<int> &arr) {
        // code here
        Trie trie;
        int n = arr.size(), res = 0;
        
        for(int i=0; i<n; ++i)
            trie.insert(arr[i]);
        
        for(int i=0; i<n; ++i)
            res = max(res, trie.getMax(arr[i]));
        
        return res;
    }
};
