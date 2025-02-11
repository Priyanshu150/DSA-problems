#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// For every node have a lowerlimit and higherlimit if any node is not in the limit that tree can't be a BST
// For root node, the limit will be [-infinity, infinity]
// going on the left of node, the limit will be [lowerlimit, node->data]
// going on the right of node, the limit will be [node->data, higherlimit]

// Link :- https://www.geeksforgeeks.org/problems/check-for-bst/1