#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// For every node we'll calculate the maximum value of with or without taking the current node
// for this we'll need left and right subtree information, hence postOrder traversal
// Every node will return these 2 values 
// final answer for us will be maximum among both values whatever root returns 

// Link :- https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

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
    typedef pair<int,int> pi; 
  
    pi solve(Node *node){
        // base case 
        if(!node)
            return {0, 0};
        
        // left subtree call 
        pi ltVal = solve(node -> left);
        // right subtree call 
        pi rtVal = solve(node -> right);
        
        // with taking current node the maximum value we can form
        int withNode = node -> data + ltVal.second + rtVal.second;
        // without taking current node the maxiumum value that we can get 
        int withoutNode = max({ltVal.first + rtVal.first, ltVal.first + rtVal.second, 
            ltVal.second + rtVal.first, ltVal.second + rtVal.second
        });
        // return both with and without current node value for further exploration
        return {withNode, withoutNode};
    }
    
  public:
    int getMaxSum(Node *root) {
        // code here
        pi val = solve(root);
        return max(val.first, val.second);
    }
};