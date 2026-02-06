#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*log(n))   
//Space complexity :- O(1)

// Approach :- 
// sort all the 3 array in ascending order 
// traverse on all 3 from starting and find the diff among triplet 
// update the triplet answer based on the requirement
// increment the pointer of the array which has lowest value
// so that larger and smaller among triplet comes more closer 

//Link :- https://www.geeksforgeeks.org/problems/happiest-triplet2921/1

class Solution {
  private:
    int findMinDiff(int val1, int val2, int val3){
        // find the maximum and minimum element among triplet 
        int maxi = max({val1, val2, val3});
        int mini = min({val1, val2, val3});
        
        return maxi - mini;  // diff of both will be diff of triplet 
    }
  
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // sort all the three array 
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        
        // declare ans array with 3 size 
        vector<int> ans(3);
        int i=0, j=0, k=0;  // intialize 3 ptr for 3 arrays 
        int n = a.size(), minDiff = INT_MAX;
        
        // traverse in all 3 at the same time 
        while(i<n && j<n && k<n){
            // find the curr Diff among the triplet 
            int currDiff  = findMinDiff(a[i], b[j], c[k]);
            bool updateAns = false;
            
            // curr diff turns out to be smaller than previous 
            if(currDiff < minDiff){
                // update the ans array and diff 
                minDiff = currDiff;
                updateAns = true;
            }
            // curr diff turns out to be equal to previous 
            else if(currDiff == minDiff){
                // find the sum of both array 
                int currSum = a[i] + b[j] + c[k];
                int ansSum = ans[0] + ans[1] + ans[2];
                
                // curr sum is less than previous update the answer 
                if(currSum < ansSum){
                    updateAns = true;
                }
            }
            // update the answer with current value 
            if(updateAns){
                ans[0] = a[i];
                ans[1] = b[j];
                ans[2] = c[k];
            }
            
            // move the pointer based on the smallest value to bring 
            // smallest and largest more closer 
            if(a[i] <= b[j] && a[i] <= c[k])
                i++;
            else if(b[j] <= c[k] && b[j] <= a[i])
                j++;
            else
                k++;
        }
        // sort the answer array in decreasing order 
        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
    }
};