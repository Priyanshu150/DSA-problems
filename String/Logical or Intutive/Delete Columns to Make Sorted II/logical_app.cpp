#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(m*n)
//Space complexity :- O(n) 

// Approach :-
// we'can check each char column wise and if the they are not in lexiographically sorted 
// then we can delete that complete
// only one test case will fail here for this which it when previous row having same char i.e (x, x, x) or other
// for that case we can maintain an array which tell us which portion of previous row was sorted 
// we'll maintain those array and while checking the condition for deletion 
// we can also check for previous row is sorted or not 
// if sorted then no need to check the char order 

//link :- https://leetcode.com/problems/delete-columns-to-make-sorted-ii/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), deletion = 0;
        // store the sorted information of previous row 
        vector<int> alreadySorted(n, false);

        for(int col=0; col<m; ++col){
            bool deleted = false;

            for(int row=0; row<n-1; ++row){
                if(!alreadySorted[row] && strs[row][col] > strs[row+1][col]){
                    deletion++;
                    deleted = true;
                    break;
                }
            }
            if(deleted)     continue;

            for(int i=0; i<n-1; ++i){
                alreadySorted[i] |= (strs[i][col] < strs[i+1][col]);
            }
        }
        return deletion;
    }
};