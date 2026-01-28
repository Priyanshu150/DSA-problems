#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*sum + n*log(n))
// Space complexity :- O(n*sum)

// Approach :-  
// try exploring all the combination using take or not take case 
// since negative sum is also present we've to explore all case 
// we can't use sum >= arr[ind] condition as it'll prune some of the branch which can be pottential answer
// 2 parameter are changing sum and ind, hence it can be memoized
// but we've to handle sum properly as it can be negative also 
// also sort the array 

// link :- https://www.geeksforgeeks.org/problems/count-the-subset-with-sum-equal-to-k/1


class Solution {
private:
    unordered_map<string, int> memo;
    
    int solve(int ind, int sum, vector<int>& arr, int n) {
        // Base cases
        if(sum == 0) return 1;
        if(ind == n || sum < 0) return 0;
        
        // Memoization
        string key = to_string(ind) + "#" + to_string(sum);
        if(memo.count(key)) return memo[key];
        
        // Don't take
        int notTake = solve(ind + 1, sum, arr, n);
        
        // Take (handles negatives correctly)
        int take =  solve(ind + 1, sum - arr[ind], arr, n);
        
        return memo[key] = notTake + take;
    }
    
public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size(), sum = 0;
        sum = accumulate(arr.begin(), arr.end(), sum);
        
        if(k > sum)     return 0;
        
        // sort the array 
        sort(arr.begin(), arr.end());
        memo.clear();  // Reset for multiple calls
        return solve(0, k, arr, n);
    }
};
