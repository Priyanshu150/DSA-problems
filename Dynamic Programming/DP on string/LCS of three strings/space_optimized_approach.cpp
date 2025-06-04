#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^3)
// Space complexity :- O(n^2)

// Approach :- 
// using lcs on 2 string space optimized approach

// Link :- https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1

class Solution{
    public:
        int LCSof3 (string a, string b, string c, int n1, int n2, int n3){
            vector<vector<int>> prev(n2+1, vector<int> (n3+1, 0));
            vector<vector<int>> curr(n2+1, vector<int> (n3+1, 0));
            
            for(int i=1; i<=n1; ++i){
                for(int j=1; j<=n2; ++j){
                    for(int k=1; k<=n3; ++k){
                        if(a[i-1] == b[j-1] && b[j-1] == c[k-1])
                            curr[j][k] = 1 + prev[j-1][k-1];
                        else
                            curr[j][k] = max({prev[j][k], curr[j-1][k], curr[j][k-1]});
                    }
                }
                prev = curr;
            }
            return prev[n2][n3];
        }
};