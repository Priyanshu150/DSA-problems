#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*m)
//Space complexity :- O(n*m)

//link :- https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size(), sum = 0;
        // initialize the 2 1d dp array with INT_MAX
        vector<int> prev(m+1, 0), curr(m+1, 0);

        // initialize the base case when s1 is expired and only s2 is present 
        for(int j=0; j<m; ++j){
            sum += s2[j];
            prev[j+1] = sum;
        }
        sum = 0;        // reset the sum value 

        for(int i=1; i<=n; ++i){
            sum += s1[i-1];
            // initialize the base case when s2 is expired and only s1 is present 
            curr[0] = sum;

            for(int j=1; j<=m; ++j){
                // both string having same char at {i, j} index 
                if(s1[i-1] == s2[j-1]){
                    curr[j] = prev[j-1];
                }else{
                    int opn1 = s1[i-1] + prev[j];    // delete the char from s1 
                    int opn2 = s2[j-1] + curr[j-1];    // delete the char from s2 
                    curr[j] = min(opn1, opn2);         // take min of both option 
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};