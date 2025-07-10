#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*L)
// Space complexity :- O(N*L)

// Approach :-  
// insert all the words into the the trie 
// use bfs technique to search into the trienode
// starting from the top level to the last level where the node is present 


// links :- https://www.geeksforgeeks.org/problems/find-the-longest-string--170645/1


class TrieNode{
  private:
    TrieNode* children[26];
    bool flag;
  
  public:
    TrieNode(){
        flag = false;
        
        for(int i=0; i<26; ++i)
            children[i] = nullptr;
    }
  
    bool containsKey(char ch){
        return (children[ch - 'a'] != nullptr);
    }
    
    void set(TrieNode* nd, char ch){
        children[ch - 'a'] = nd;
    }
    
    TrieNode* get(char ch){
        return children[ch - 'a'];
    }
    
    bool isEnd(){
        return flag;
    }
    
    void setEnd(){
        flag = true;
    }
};

class Trie{
  private:
    TrieNode* root;

  public:
    Trie(){
        root = new TrieNode();
    }
    
    void insertWord(string word){
        TrieNode* temp = root;
        
        for(int i=0; i<word.size(); ++i){
            if(!temp -> containsKey(word[i]))
                temp -> set(new TrieNode, word[i]);
            
            temp = temp -> get(word[i]);
        }
        temp -> setEnd();
    }
    
    string bfs(){
        string ans = "";
        TrieNode* node = root;
        queue<pair<TrieNode*, string>> q;
        q.push({node, ""});
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TrieNode* curr = q.front().first;
                string s = q.front().second;
                q.pop();
                
                if(curr != root && !curr ->isEnd())
                    continue;
                
                for(int j=0; j<26; ++j){
                    char ch = ('a'+j);
                    if(curr -> get(ch) != nullptr)
                        q.push({curr -> get(ch), s+ch});
                }
                if(ans.size() < s.size())   
                    ans = s;
            }
        }
        return ans;
    }
};

class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
        Trie* node = new Trie();
        
        for(auto word: words){
            node -> insertWord(word);
        }
        
        return node -> bfs();
    }
};