#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// use map to collect the the name based on their absolute diff with x 
// it's keep the diff sorted and also we're maintain <int,vector<int>> so multiple number can be handled


//Link :- https://www.geeksforgeeks.org/problems/sort-by-absolute-difference-1587115621/1

class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        map<int,vector<int>> mp;
        
        for(auto num: arr){
            int diff = abs(x - num);
            mp[diff].push_back(num);
        }
        int ind = 0;
        
        for(auto it: mp){
            for(auto num: it.second){
                arr[ind] = num;
                ind++;
            }
        }
    }
};