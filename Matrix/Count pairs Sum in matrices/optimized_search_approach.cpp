#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n*(n+n))
// Space complexity :- O(1)

// Approach :- 
// For every cell value in mat1 find wheather the target(x - mat1[i]) exist in matrix2 
// Since the array is sorted in assecending order there will only exist one element in matrix2
// In matrix, start will the last element of first row
// if the target < mat[i][j], the increment the row ptr
// else if target > mat[i][j], then decrement the col ptr

//Link :- https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1

class Solution {
  private:
    bool find(vector<vector<int>> &mat2, int &n, int &ele){
        int r=0, c=n-1;
        while(c >= 0 && r<n){
            if(mat2[r][c] == ele)      return true;
            else if(mat2[r][c] < ele)   r++;
            else    c--;
        }
        return false;
    }
    
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int cnt = 0, n = mat1.size();
	    for(int i=0; i<n; ++i){
	        for(int j=0; j<n; ++j){
	            int ele = x-mat1[i][j];
	            if(ele < 0)     continue;
	            if(find(mat2, n, ele))
	                cnt++;
	        }
	    }
	    return cnt;
    }
};