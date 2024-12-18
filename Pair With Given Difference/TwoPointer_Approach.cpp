#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int target) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    if(target < 0)      target *= -1;
    int i=0, j=1;
    
    while(j<n){
        int diff = arr[j] - arr[i];
        if(diff == target)
            return 1;
        if(diff < target)
            j++;
        else    i++;
        
        if(i == j)
            j++;
    }
    return 0;
}