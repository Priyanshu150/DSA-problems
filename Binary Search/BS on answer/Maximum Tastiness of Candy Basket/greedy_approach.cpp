#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n) + n*log(max_diif))  
// Space complexity :- O(n)

// Approach :- 
// sort the array to bring price as closest as possible 
// the answer will lie in a certain range hence we can apply binary search here 
// where the low will be lowest difference among pair and high will highest difference 
// for every mid/diff we can check wheather that possible or not
// if yes we try to increase our answer by low = mid+1 
// otherwise we decreament our difference by high = mid-1
// For checking a difference exist, count the number with different greater than or equal to the value  
// for that we traverse the array maintaining 2 variables prev and cnt 
// where cnt is count of numbers and prev is the last number of series taken
// on each number we can check wheather if the difference is greater than given difference 
// the take that number in consideration i.e. prev = curr_num and cnt increase by 1 


// Link :- https://leetcode.com/problems/maximum-tastiness-of-candy-basket/

class Solution {
private:
    bool isPossible(int diff, vector<int> &price, int &k, int &n){
        int cnt = 1, prev = price[0];

        for(int i=1; i<n; ++i){
            if((price[i] - prev) >= diff){
                prev = price[i];
                cnt++;
            }
        }
        return cnt >= k;
    }

public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size(), low = INT_MAX, high = price[n-1] - price[0];

        for(int i=1; i<n; ++i)
            low = min(low, price[i] - price[i-1]);
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, price, k, n))       low = mid+1;
            else        high = mid-1;
        }
        return high;
    }
};