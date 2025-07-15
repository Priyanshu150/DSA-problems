#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(log(max_element)*n*log(m))   
//Space complexity :- O(1)

// Approach :-
// The size of row and column is both odd the multiplication of both will give an odd number 
// median of odd size array is middle element of the array 
// i.e. now the question becomes the find the (n*m)/2 + 1 th smallest element in the array 
// we can use binary search on answer approach 
// where low will  be lowest value from 1st column and high will be highest number from last column
// count the number which are smaller than or equal to mid value 
// if the cnt >= (n*m)/2 + 1, store the answer and try to find smaller number i.e high = mid-1
// else try to find the larger number ie. low = mid+1;
// we store answer on case >= because there might be chance that 7 is our answer and all the number is 7
// In that case we'll get the count of number >=  (n*m)/2 + 1
// for find the count we can apply upper bound on every row
// and accumulate the count of number smaller or equal to current_number 


//Link :- https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

class Solution {
  private:
    int smallerOrEqualCount(int num, vector<vector<int>> &mat, int &n, int &m){
        int cnt = 0;
        
        for(int row=0; row<n; ++row){
            int ind = upper_bound(mat[row].begin(), mat[row].end(), num) - mat[row].begin();
            cnt += ind;
        }
        return cnt;
    }
  
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(), m = mat[0].size(), res(-1), k = (n*m)/2 + 1;
        int low = 1, high = 2000;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            int cnt = smallerOrEqualCount(mid, mat, n, m);
            if(cnt >= k){
                res = mid;
                high = mid-1;
            }
            else if(cnt < k){
                low = mid+1;
            }
        }
        return res;
    }
};
