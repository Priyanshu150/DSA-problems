#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       
//Space complexity :- O(N)  

int diffPossible(vector<int> &arr, int target) {
    int n = arr.size();
    unordered_set<int> st;
    
    for(int i=0; i<n; ++i){
        if(st.count(arr[i] - target))
            return 1;
        
        st.insert(arr[i]);
    }
    return 0;
}