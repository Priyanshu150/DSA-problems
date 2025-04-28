#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// using recursive approach, we'll maintain two value so return type can be pair of integers
// one of the value by including the current value and not including the child values
// other will be sum of value returned from left child and right child 


//link :- https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  private:
    pair<int,int> solve(Node* node){
        if(!node)
            return {0, 0};
        
        pair<int,int> lt = solve(node -> left);
        pair<int,int> rt = solve(node -> right);
        
        pair<int,int> ans;
        ans.first = node -> data + lt.second + rt.second;
        ans.second = max(lt.first, lt.second) + max(rt.first, rt.second);
        return ans;
    }
  
  public:
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        // code here
        pair<int,int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};