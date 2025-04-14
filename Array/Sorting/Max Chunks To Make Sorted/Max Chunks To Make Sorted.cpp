#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), chunks = 0, max_seen = 0;

        for(int i=0; i<n; ++i){
            max_seen = max(max_seen, arr[i]);
            if(max_seen == i)
                chunks++;
        }
        return chunks;
    }
};

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ind = 0, n = arr.size(), chunks = 0;

        while(ind < n){
           if(arr[ind] != ind){
                int maxInd = arr[ind];
                while(ind <= maxInd){
                    maxInd = max(maxInd, arr[ind]);
                    ind++;
                }
                --ind;
            }
            ind++;
            chunks++;
        }
        return chunks;
    }
};