#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       
//Space complexity :- O(1)  

int diffPossible(vector<int> &arr, int target) {
    int n = arr.size(), i = 0, j = 1;
    
    while(j<n){
        int diff = arr[j] - arr[i];
        if(diff == target)
            return 1;
        else if(diff < target)
            j++;
        else    i++;
            
        if(i == j)
            j++;
    }
    return 0;
}