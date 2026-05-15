#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*log(n) + n*log(sum))   
//Space complexity :- O(1)

// Approach :-
// we can use binary search on answers as the answer will always lie in a range 
// and it will satisfy the property that not possible for some range followed by possible for rest of them 
// low will be 1 and high will be  sum of all the minimum energy in the array 
// we also need to sort the array in order for the possible funtion to work   
// we'll sort them based on higher difference value before the higher the difference the more energy we'll have at end 

//Link :- https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/

class Solution {
private:
    typedef long long ll;

    bool isPossible(int energy, vector<vector<int>>& tasks, int &n){
        for(int i=0; i<n; ++i){
            // energy needed for next task is more than current energy level 
            if(tasks[i][1] > energy){
                return false;
            }
            // decrement the energy used from overall 
            energy -= tasks[i][0];
        }
        return true;
    }

public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // sort the array based on the maximum profit can be earned 
        sort(tasks.begin(), tasks.end(), [&](vector<int> &task1, vector<int> &task2){
            int diff1 = task1[0] - task1[1];
            int diff2 = task2[0] - task2[1];

            return diff1 < diff2;
        });

        int n = tasks.size();
        ll low = 1, high = 1, res = 1;

        // sum of all the minimum energy required 
        for(int i=0; i<n; ++i){
            high += tasks[i][1];
        }

        // standard bs on answer 
        while(low <= high){
            ll mid = low + (high - low)/2;

            // check if it's possible to complete the task with mid as starting energy 
            if(isPossible(mid, tasks, n)){
                res = mid;
                // decrease the answer to find a lower energy value 
                high = mid-1;
            }
            else{
                // increase the answer to find the larger valid energy value 
                low = mid+1;
            }
        }
        return res;
    }
};
