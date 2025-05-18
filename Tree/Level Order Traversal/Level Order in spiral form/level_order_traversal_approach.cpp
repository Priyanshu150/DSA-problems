#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// traverse the tree using level order traversal and maintain a flag to push alternating sequence 

//Link :- https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1

class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        vector <int> ans;
    	if(!root)
    	    return ans;
    	
    	queue<Node*> q;
    	q.push(root);
    	bool flag = true;
    	
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int> level;
    	    while(size--){
    	        Node* n = q.front();
    	        q.pop();
    	        level.push_back(n -> data);
    	        if(n -> left)
    	            q.push(n -> left);
    	        if(n -> right)
    	            q.push(n -> right);
    	    }
    	    if(flag)
    	        reverse(level.begin(), level.end());
    	        
    	    for(auto it : level)
    	        ans.push_back(it);
    	        
    	    flag = !flag;
    	    level.clear();
    	}
    	return ans;
    }
};