#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*word_length)
// Space complexity :- O(N)

// Approach :- 
// use trie data structure to insert node at every level where the root is '/'
// use map to store all these string value 
// use bfs to find the directory which satisfies our conditions 


// Link :- https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

struct trienode{
    bool wordEnd = false;
    unordered_map<string, trienode*> child;
};

class Solution {
private:
    void insertFolder(string folder, trienode* node){
        int i = 1;
        while(i<folder.size()){
            string name;
            while(i < folder.size() && folder[i] != '/'){
                name.push_back(folder[i]);
                ++i;
            }
            if(node -> wordEnd)     return;

            if(!node -> child.count(name))
                node -> child[name] = new trienode;
            
            node = node -> child[name];
            ++i;
        }
        node -> wordEnd = true;
    }

    void searchTrie(trienode* node, vector<string> &res, string path){
        if(!node)       return;
        if(node -> wordEnd){
            path.pop_back();
            res.push_back(path);
            return;
        }

        for(auto [name, child]: node -> child){
            searchTrie(child, res, path + name + "/");
        }
    }

public:
    vector<string> removeSubfolders(vector<string>& folders) {
        trienode* root = new trienode;

        for(string folder: folders)
            insertFolder(folder, root);
        
        vector<string> res;
        searchTrie(root, res, "/");
        return res;
    }
};