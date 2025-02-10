#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Traverse to every node and  Use either postorder / preorder traversal technique
// Use the technique of subarray sum equal to target
// Use hashmap to store the sum and hence calculate the result from that

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
        if(!node)   return;
        
        sum += node -> data;
        int target = sum - k;
        if(mp.count(target))
            res += mp[target];
        
        mp[sum] += 1;
        
        solve(node -> left, k, sum, res);
        solve(node -> right, k, sum, res);
        
        mp[sum] -= 1;
        sum -= node -> data;
    }
  
  public:
    int sumK(Node *root, int k) {
        // code here
        int sum = 0, res = 0;
        mp[0] = 1;
        solve(root, k, sum, res);
        return res;
    }
};