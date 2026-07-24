#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)
// Space complexity :- O(1)

// Approach :- 
// For every node we've to return 2 values first current value of node, maximum length seen till now
// current value can be use to compare later with parent 
// maintain the maximum length accross all the paths 
// use post order traversal, then compare the value from left and right subtree 

// Links :- https://www.geeksforgeeks.org/problems/longest-consecutive-sequence-in-binary-tree/1

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  private:
    pair<int,int> solve(Node* node, int &res){
        // base case: when node is null 
        if(node == nullptr){
            return {-10, 0};
        }
        // use post order traversal 
        pair<int,int> lt = solve(node -> left, res);
        pair<int,int> rt = solve(node -> right, res);
        
        int countOfNodes = 1;
        // left subtree forms a path with given condition 
        if(lt.first == (1 + node -> data)){
            countOfNodes = max(countOfNodes, lt.second + 1);
        }
        // rigth subtree forms a path with given condition 
        if(rt.first == (1 + node -> data)){
            countOfNodes = max(countOfNodes, rt.second + 1);
        }
        // maintain maximum path node accross all path 
        res = max(res, countOfNodes);
        
        return {node -> data, countOfNodes};        // {current node's value, max count of node till now}
    }
  
  public:
    int longestConsecutive(Node* root) {
        int res = -1;       // variable to track answer
        solve(root, res);   // call recucrsion 
        
        // count of nodes in path is 0 or 1 then -1 will be answer otherwise res 
        return (res > 1) ? res : -1;    
    }
};