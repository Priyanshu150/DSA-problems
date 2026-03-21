#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n)
// Space complexity :- O(n)

// Approach :-  
// we've to try all possibilites of making the BST
// we can sort the arrray to make nodes sorted in increasing order that way we can making nodes will becomes easier 
// for updatng the answer array and sorting the element we can use hash map to store and sort at the same time 
// for any configuration we can select any node as a root node and split the nodes into left and right halfes 
// since the nodes are sort the configuration will always yeild a BST 
// using recursion, create all trees and base case will be f[0] = f[1] = 1
// total ways will be number of ways from left subtree * number of ways from right subtree 
// Instead of calling it again we can use dp and store it 
// for every node count the number of left and right node use the dp table to find the answer 
// and update in answer array using index stored in hash table 


// links :- https://www.geeksforgeeks.org/problems/number-of-bst-from-array/1

class Solution {
  private:
    void catlanNumber(int nodeCnt, vector<int> &dp){
        dp[0] = dp[1] = 1;
        
        for(int n = 2; n <= nodeCnt; ++n){
            for(int i=1; i<=nodeCnt; ++i){
                dp[n] += (dp[i-1] * dp[n - i]);
            }
        }
    }
  
  public:
    vector<int> countBSTs(vector<int>& arr) {
        // find all the catlan number values 
        vector<int> dp(10, 0);
        catlanNumber(7, dp);
        
        int n = arr.size();
        vector<int> ans(n, 0);      // store the count of answer
        map<int,int> arrInd;        // hash array values to index 
        
        // update the details of element to index mapping 
        for(int i=0; i<n; ++i){
            arrInd[arr[i]] = i;
        }
        // node on left intitailly will 0 and on right will be n-1 
        int nodesOnLeft = 0, nodesOnRight = n-1;
        
        // traverse on the sorted keys 
        for(auto it: arrInd){
            int ele = it.first;
            int ind = it.second;
            // total number of ways = ways from left subtree * ways from right subtree
            ans[ind] = dp[nodesOnLeft] * dp[nodesOnRight];
            
            // update the node count info 
            nodesOnLeft += 1;
            nodesOnRight -= 1;
        }
        return ans;
    }
};
