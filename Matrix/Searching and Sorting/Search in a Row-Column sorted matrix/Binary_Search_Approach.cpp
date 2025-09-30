#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*log(M))
//Space complexity :- O(1)

class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size(), m = mat[0].size();
        
        for(int row=0; row<n; ++row){
            int low = 0, high = m-1;
            
            while(low <= high){
                int mid = low + (high - low)/2;
                
                if(mat[row][mid] == x)
                    return true;
                else if(mat[row][mid] < x)
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return false;
    }
};