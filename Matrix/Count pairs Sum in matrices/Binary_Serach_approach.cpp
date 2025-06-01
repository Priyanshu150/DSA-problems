#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n*log(n*n))
// Space complexity :- O(1)

//Approach :- 
// For every cell value in mat1 find wheather the target(x - mat1[i]) exist in matrix2 
// Since the array is sorted in assecending order there will only exist one element in matrix2
// Apply binary search on mat2 to find the target 

//Link :- https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1

class Solution {
  private:
    bool binarySearch(vector<vector<int>> &mat, int target, int &n){
        int low = 0, high = n*n-1, ind = -1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            int row = mid/n, col = mid%n;
            
            if(mat[row][col] == target){
                return true;
            }
            else if(mat[row][col] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
  
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n = mat1.size(), res = 0;
        
        for(int row=0; row<n; ++row){
            for(int col=0; col<n; ++col){
                if(x <= mat1[row][col])
                    continue;
                
                int target = x - mat1[row][col];
                if(binarySearch(mat2, target, n)){
                    res += 1;
                }
            }
        }
        return res;
    }
};