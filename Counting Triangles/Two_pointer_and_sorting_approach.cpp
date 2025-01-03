#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*log(N) + N*N)       
//Space complexity :- O(1)    

//Approach :-
// (a+b) > c, (a+c) > b, (b+c) > a are the condition to satisfy the line segment are triangle
// If we take smallest two value and which is greater than third value then it's a triangle
// i.e (a+b) > c   where c > a && c > b
// Applying 2 pointer and fixing the value of c 
// find (a+b) > c
// if sum > c   => length += (rInd - lInd)  and rInd-- (find other window)
// else   lInd++    (increase the sum )


int nTriang(vector<int> &arr) {
    int n = arr.size(), cnt = 0;
    const int m = 1e9+7;
    sort(arr.begin(), arr.end());
    
    for(int i=n-1; i>=2; --i){
        int l = 0, r = i-1;
        while(l < r){
            int sum = arr[l] + arr[r];
            if(sum > arr[i]){
                cnt = (cnt % m) + ((r-l)%m);
                r--;
            }
            else        l++;
        }
    }
    return cnt;
}