#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*log(n))
//Space complexity :- O(n)

// Approach :-
// sort the array and count the number of candies we and take 
// Take the that number of candies from starting and ending which will give the min and max cost 


//link :- https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1

class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(begin(prices), end(prices));
        int n = prices.size();
        int toBuy = n/(k+1);
        toBuy += (n%(k+1))>0 ? 1 : 0;
        vector<int> ans(2, 0);
        
        for(int i=0; i<toBuy; ++i){
            ans[0] += prices[i];
            ans[1] += prices[n-i-1];
        }
        return ans;
    }
};