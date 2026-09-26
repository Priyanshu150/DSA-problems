#include <bits/stdc++.h>
using namespace std;

// Time complexity :- O(n^2)
// Space complexity :- O(n)

// Approach :- 
// 1. Create a temp array to store {radius, height} of each disc.
// 2. Sort the temp array by height in descending order.
// 3. Apply the standard Longest Increasing Subsequence (LIS) algorithm on the sorted array,
//   where we check if the radius and height of the current disc is greater than the previous disc.


//Link :- https://www.geeksforgeeks.org/problems/stacking-up-discs1315/1

class Solution {
  private:
    bool check(pair<int,int>& p1, pair<int,int>& p2) {
        // radius and height constraint check
        return (p1.first > p2.first) && (p1.second > p2.second);   
    }

    int lis(int n, vector<pair<int,int>>& arr) {
        int ans = 0;
        vector<int> dp(n, 0);

        // initialize each dp[i] with its own height
        for(int i = 0; i < n; ++i)
            dp[i] = arr[i].second;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(check(arr[j], arr[i]))
                    //  add arr[i].second
                    dp[i] = max(dp[i], dp[j] + arr[i].second);  
            }
            ans = max(ans, dp[i]);  
        }
        // capture dp[0] in ans
        ans = max(ans, dp[0]);
        return ans;
    }

  public:
    int maxStackHeight(vector<int>& r, vector<int>& h) {
        int n = r.size();
        vector<pair<int,int>> temp;
        
        // create a temp array to store {radius, height}
        for(int i = 0; i < n; ++i)
            temp.push_back({r[i], h[i]});

        //  sort by height in descending order 
        sort(temp.begin(), temp.end(), [](pair<int,int> p1, pair<int,int> p2){
            return p1.second > p2.second;
        });
        
        // standard lis 
        return lis(n, temp);
    }
};