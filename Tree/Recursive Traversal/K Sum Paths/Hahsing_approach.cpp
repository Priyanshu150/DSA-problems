#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// we can store the sum while travesing on the tree 
// and can use prefix sum technique to find wheather a subarray exist or not 

// Link :- https://www.geeksforgeeks.org/problems/k-sum-paths/1


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  private:
    unordered_map<int,int> mp;
    
    void solve(Node* node, int &k, int &sum, int &res){
        // base case 
        if(!node)   return;
        
        // calculate the sum of path 
        sum += node -> data;
        // find the target of the subarray
        int target = sum - k;
        if(mp.count(target))
            res += mp[target];
        // store the contribution of the element 
        mp[sum] += 1;
        // traverse on the subtree 
        solve(node -> left, k, sum, res);
        solve(node -> right, k, sum, res);
        
        // backtrack to not interept other path contribution 
        mp[sum] -= 1;
        sum -= node -> data;
    }
  
  public:
    int sumK(Node *root, int k) {
        // code here
        int sum = 0, res = 0;
        // add 0 contribution into the map 
        mp[0] = 1;
        solve(root, k, sum, res);
        return res;
    }
};