#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// inorder of BST is sorted hence we'll use that to 
// find the closest smallest value to target using binary search 
// then find k closest element by moving left and right from that index to find the closest element to target 

// links :- https://www.geeksforgeeks.org/problems/k-closest-values/1

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private:
    void morrisTraversal(Node* root, vector<int> &inorder){
        Node* curr = root;
        
        while(curr){
            if(curr -> left == nullptr){
                inorder.push_back(curr -> data);
                curr = curr -> right;
            }
            else{
                Node* prev = curr -> left;
                while(prev -> right && prev -> right != curr)
                    prev = prev -> right;
                
                if(prev -> right == nullptr){
                    prev -> right = curr;
                    curr = curr -> left;
                }
                else{
                    prev -> right = nullptr;
                    inorder.push_back(curr -> data);
                    curr = curr -> right;
                }
            }
        }
    }
    
    int bs(vector<int> &arr, int &target, int &n){
        int low = 0, high = n-1, res = -1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] <= target){
                res = mid;
                low = mid+1;
            }
            else 
                high = mid-1;
        }
        return res;
    }
    
  public:
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        vector<int> inorder, res;
        morrisTraversal(root, inorder);
        
        int n = inorder.size();
        int ind = bs(inorder, target, n);
        int low = ind, high = ind+1;
        
        while(k > 0){
            if(low >= 0 && (high == n || abs(target - inorder[low] <= abs(target - inorder[high])))){
                res.push_back(inorder[low]);
                --low;
            }
            else{
                res.push_back(inorder[high]);
                ++high;
            }
            --k; 
        }
        return res;
    }
};