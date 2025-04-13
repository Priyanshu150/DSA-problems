#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(V+E)
// Space complexity :- O(V)              

// Approach :- 
// we'll use dfs approach to traverse on the nodes, and create a copy of each node
// while we create a copy we'll store each node in map to avoid recreating that node and retraversing
// Start from the node we will traverse on the adjacent node applying dfs repeating the same
// we'll get our new copy of graph


// Links :- https://www.geeksforgeeks.org/problems/clone-graph/1


struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
  private:
    void dfs(Node* copyNd, Node* node, unordered_map<int, Node*> &mp){
        mp[copyNd->val] = copyNd;
        
        for(auto nd: node -> neighbors){
            if(!mp.count(nd->val)){
                Node* copy = new Node(nd->val);
                dfs(copy, nd, mp);
            }
            (copyNd -> neighbors).push_back(mp[nd -> val]);
        }
    }
  
  public:
    Node* cloneGraph(Node* node) {
        // code here
        Node* copy = new Node(node->val);
        unordered_map<int, Node*> mp;
        dfs(copy, node, mp);
        return copy;
    }
};
