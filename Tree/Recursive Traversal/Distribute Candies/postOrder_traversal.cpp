#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Start with bottom-up approach if the child have extra coins it will pass it to parent
// if child is passing a coin or demanding n number of coins from parent 
// then that will be counted as a move 
// we can return the number of coins from every node needed/extra to it's parent


// Link :- https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution {
  private:
    int solve(Node* node, int &res){
        if(!node)       return 0;
        
        int leftVal = solve(node -> left, res);
        int rightVal = solve(node -> right, res);
        
        int coinsNeed = leftVal + rightVal + node -> data - 1;
        res += abs(coinsNeed);
        
        return coinsNeed;
    }
  
  public:
    int distCandy(Node* root) {
        // code here
        int res = 0;
        solve(root, res);
        return res;
    }
};