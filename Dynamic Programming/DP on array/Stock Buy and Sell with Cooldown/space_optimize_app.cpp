#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*2)  
// Space complexity :- O(1)

// Approach :-  
// Instead of using n*2 dp to store state, use constant space 

// Link :- https://www.geeksforgeeks.org/problems/buy-stock-with-cooldown/1

class Solution {
  public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<int> ahead(2, 0), curr(2, 0), ahead1(2,0);
        
        // try out all possibilities using loops
        for(int ind=n-1; ind>=0; --ind){
            // option to buy current stock 
            curr[1] = max(ahead[1], ahead[0] - arr[ind]);
            // option to sell current stock 
            curr[0] = max( ahead[0], ahead1[1] + arr[ind]);
            
            ahead1 = ahead;
            ahead = curr;
        }
        return ahead[1];
    }
};