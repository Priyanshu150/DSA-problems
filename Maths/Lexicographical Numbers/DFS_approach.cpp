#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(stack_space)

// Approach :- 
// using dfs approach try to form the lexiograpically smallest number 
// add number 1 to 9 in prev number sequencentially 


// Link :- https://leetcode.com/problems/lexicographical-numbers/

class Solution {
private:
    void dfs(int currNum, int num, vector<int> &res){
        if(currNum > num)
            return;
        
        res.push_back(currNum);

        for(int i=0; i<10; ++i){
            int newNum = currNum * 10 + i;
            dfs(newNum, num, res);
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1; i<10; ++i){
            if(i > n)       break;
            dfs(i, n, ans);
        }
        return ans;
    }
};