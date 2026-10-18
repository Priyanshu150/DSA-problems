#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

// Approach 
// 1. We can use recursion to find out the number of ways to arrange the left and right subtree.
// 2. We can use pascal triangle to find out the number of ways to arrange the left and right subtree.
// 3. We can use the formula nCr = n! / (r! * (n-r)!) to find out the number of ways to arrange the left and right subtree.

// Link :- https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/

class Solution {
private:
    typedef long long ll;
    ll mod = 1e9+7;

    vector<vector<ll>> pascalTriangle;

    ll solve(vector<int> nums){
        int n = nums.size();
        // base case 
        if(n < 3)       return 1;

        int root = nums[0];     // first value is root node 
        vector<int> left, right;

        // store left and right subtree values 
        for(int i=1; i<n; ++i){
            if(nums[i] < root)
                left.push_back(nums[i]);
            else 
                right.push_back(nums[i]);
        }
        // ways to arrange left subtree 
        ll leftWays = solve(left) % mod;
        // ways to arrange right subtree 
        ll rightWays = solve(right) % mod;
        // total ways to arrange both left and right subtree
        ll totalWays = (leftWays * rightWays) % mod;
        // ways to arrange current subtree 
        ll currWays = pascalTriangle[n-1][left.size()] % mod;

        // total ways to arrange complete tree 
        return (totalWays * currWays) % mod;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)       return 0;

        pascalTriangle.resize(n+1, vector<ll> (n+1, 1));

        // form the pascal triangle 
        for(int row=2; row<=n; ++row){
            for(int col=1; col<row; ++col){
                // caluclate the value of nCr
                pascalTriangle[row][col] = (pascalTriangle[row-1][col] + pascalTriangle[row-1][col-1])%mod;
            }
        }
        // use recursion to find out all ways 
        return (solve(nums) - 1) % mod; // subtract 1 for the inital array given 
    }
};     

