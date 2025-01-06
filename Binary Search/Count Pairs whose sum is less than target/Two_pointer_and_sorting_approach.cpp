#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*log(N) + N)
//Space complexity :- O(1)  

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code 
        int n = arr.size(), lt = 0, rt = n-1, res = 0;
        sort(arr.begin(), arr.end());
        
        while(lt < rt){
            int sum = arr[lt] + arr[rt];
            if(sum < target){
                res += (rt - lt);
                lt++;
            }
            else    rt--;
        }
        return res;
    }
};