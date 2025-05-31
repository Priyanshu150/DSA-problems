#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n)
// Space complexity :- O(k)

//Approach :- 
// Use heap to store the first k element of sorted order 

//Link :- https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1

int kthSmallest(int mat[MAX][MAX], int n, int k){
    priority_queue<int> pq;
    int m = k;
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<n && j<m; ++j){
            if(pq.size() < k){
                pq.push(mat[i][j]);
                // cout<<mat[i][j]<<" ";
            }
            else if(pq.top() > mat[i][j]){
                pq.pop();
                pq.push(mat[i][j]);
                // cout<<mat[i][j]<<" ";
            }
        }
        m--;
        // cout<<endl;
    }
    return pq.top();
}

