#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(m * log n)
//Space complexity :- O(1) 

// Approach :-
// we'll apply bs search on answer approach, low will be 0 and 
// high will be min_element * n * (n+1) / 2, because n donuts need to be made 
// hence multiplying cost with sum of n natural numbers 
// for find the donuts made by each chef, we can use same technique to find 
// by solving the quadratic solution we'll get the donut value 

//link :- https://www.geeksforgeeks.org/problems/minimum-time-to-fulfil-all-orders/1

class Solution {
  private:
    int donutByChef(int t, int rank){
        // donut make by each donut using quadratice equation 
        int constant = (t*2)/rank;
        int val = sqrt(1 + 4*constant);
        int donut = (val - 1)/2;
        return donut;
    }
  
    bool isPossible(int t, vector<int> &ranks, int &n, int &m){
        int donuts = 0;
        
        // for every chef's rank 
        for(int i=0; i<m ; ++i){
            int donut = donutByChef(t, ranks[i]);
            donuts += donut;
            
            if(donuts >= n)
                return true;
        }
        return false;
    }
  
  public:
    int minTime(vector<int>& ranks, int n) {
        int mini = *min_element(ranks.begin(), ranks.end());
        int high = mini*n*(n+1)/2;
        int m = ranks.size(), low = 1, res = high;
        
        // bs on answer 
        while(low <= high){
            int mid = low + (high - low)/2;
            
            // check with the current mid i.e time it's possible to make the dounuts or not
            if(isPossible(mid, ranks, n, m)){
                res = mid;
                high = mid-1; // try to decrease the time 
            }else{
                // increase the time in order to find an answer 
                low = mid+1;
            }
        }
        return res;
    }
};