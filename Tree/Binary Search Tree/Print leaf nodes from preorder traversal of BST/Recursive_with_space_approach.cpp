#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*log(n))
// Space complexity :- O(n)              

// Approach 
// BST property :- Left value <= Root's value <= right value and inorder is sorted
// similarly in preorder we'll have (root , left, right) 
// using inorder and preorder by applying recursion find the next left node using tree formation tecnique


// Links :- https://www.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1

class Solution {
  private:
    vector<int> res, inorder;
    unordered_map<int,int> mp;
    
    void solve(int ps, int pe, int is, int ie, vector<int> &preorder){
        if(ps > pe)     return;
        if(ps == pe){
            res.push_back(preorder[ps]);
            return;
        }
        int ind = mp[preorder[ps]], len = ind - is;
        solve(ps+1, ps+len, is, ind-1, preorder);
        solve(ps+len+1, pe, ind+1, ie, preorder); 
    }
  
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        int n = preorder.size();
        inorder = preorder;
        sort(inorder.begin(), inorder.end());
        
        for(int i=0; i<n; ++i)
            mp[inorder[i]] = i;
            
        solve(0, n-1, 0, n-1, preorder);
        return res;
    }
};
