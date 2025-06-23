#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// using every number calulate the value by substituting into eqn A*x^2 + B*x + C
// where A, B, C are give and x is the current number 

//Link :- https://www.geeksforgeeks.org/problems/sort-the-given-array-after-applying-the-given-equation0304/1

class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        vector<int> ans;
        
        for(auto x: arr){
            int val = A*x*x + B*x + C;
            ans.push_back(val);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
