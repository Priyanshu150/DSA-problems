#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)
// Space complexity :- O(n)              

// Approach 
// BST property :- Left value <= Root's value <= right value 
// similarly in preorder we'll have (root , left, right) 
// if current node is considered as root then on left side the node having smaller value will be in left subtree
// and the node having larger value will be in right subtree
// using stack to replicate the same concept
// push the first node into the stack 
// as long as curr value is less than st.top() means we're in left subtree push that node into the stack
// otherwise in right substree save the last node of left subtree which will be st.top()
// pop out all the element which are greater than st.top()
// push the node in the result only when the total poped node is greater than 2 representing atleast 2 nodes are present in subtree



// Links :- https://www.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1

class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        int n = preorder.size();
        stack<int> st;
        vector<int> res;
        
        st.push(preorder[0]);
        for(int i=1; i<n; ++i){
            if(preorder[i] < st.top())
                st.push(preorder[i]);
            else{
                int temp = st.top(), cnt = 0;
                while(!st.empty() && preorder[i] > st.top()){
                    st.pop();
                    cnt++;
                }
                st.push(preorder[i]);
                if(cnt > 1)
                    res.push_back(temp);
            }
        }
        res.push_back(st.top());
        return res;
    }
};
