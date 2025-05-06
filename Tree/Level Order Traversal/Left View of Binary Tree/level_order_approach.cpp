#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(n)

// Approach :-
// Apply level order traversal
// store every first node in every level that will be our answer

// Link :- https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(!root)   return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size(), cnt = 0;
            
            while(cnt < sz){
                Node* nd = q.front();
                q.pop();
                
                if(cnt == 0)
                    ans.push_back(nd -> data);
                
                if(nd -> left)      q.push(nd -> left);
                if(nd -> right)     q.push(nd -> right);
                
                cnt++;
            }
        }
        return ans;
    }
};