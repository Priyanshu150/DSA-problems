#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*log(N))
// Space complexity :- O(N)

// Approach :-  
// optimizing from the brute force approach 
// how the number of badPair already exist in the array 
// badPair can also be generate when the array is updated 
// use ordered set to keep track of {sum, index} to update the array 
// add every sum and index into the set initially and the updated once post merging 
// use two array to keep track of prevInd and nextInd of current element 
// Alternatively doubly linked list can also be used 
// update the index post merging and count the number of operations which was performed 

// Algorithm :- 
// find the min sum and index from the set 
// using curr_index find the prev, next, next to next index 
// delete the previous sum and find the new sum by merging curr_ind and next ind 
// check wheater any new bad pair are forming 
// i.e. if previous good pair turn into bad or vice versa 
// case 1 :- {a, {b+d}}  or Case 2 :- {{b+c}, d}
// delete the neighbour index also which was affected as part of merging 
// add the new sum along with new indexes 
// update the prevInd and nextInd based on the updation 
// update the new sum in the array as we're acessing it through indexes 
// lastly count each operatioin number being performed that can be our answer 

// links :- https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/

class Solution {
private:
    typedef long long ll;

public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size(), badPairs = 0;
        vector<ll> temp(n);

        vector<int> prevInd(n), nextInd(n);
        set<pair<ll, int>> sumPairs;         // {sum, index}

        // traverse from left to right 
        for(int i=0; i<n; ++i){
            if(i > 0){
                //count number of pairs which are not already sorted in non-decreasing order
                if(nums[i] < nums[i-1])
                    badPairs++;
                
                // store every adjacent pair sum with index into the ordered set 
                sumPairs.insert({nums[i]+nums[i-1], i-1});
            }
            // store prev and next index for the current index 
            prevInd[i] = i-1;
            nextInd[i] = i+1;
            // add the element of the array into the new array to avoid overflow 
            temp[i] = nums[i];
        }
        int operations = 0; 

        // until bad pairs exist the array will not be sorted 
        while(badPairs > 0){
            // find the adjacent index in the array 
            int first = sumPairs.begin() -> second;
            int second = nextInd[first];
            ll sum = temp[first] + temp[second];

            // and their neighbour indexes 
            int firstLeft = prevInd[first];
            int secondRight = nextInd[second];

            // delete the pair which has been merged 
            sumPairs.erase(sumPairs.begin());
        
            if(temp[first] > temp[second]){
                badPairs--;
            }

            // case 1 :- {a, {b+c}}
            if(firstLeft >= 0){
                // previously it was not sorted and now it's
                if(temp[firstLeft] > temp[first] && temp[firstLeft] <= sum)
                    badPairs--;
                // previously it was sorted and now it's not
                else if(temp[firstLeft] <= temp[first] && temp[firstLeft] > sum)
                    badPairs++;
            }
            // case 2 :- {{b+c}, d}
            if(secondRight < n){
                 // previously it was sorted and now it's not
                if(temp[second] <= temp[secondRight] && sum > temp[secondRight])
                    badPairs++;
                // previously it was not sorted and now it is
                else if(temp[second] > temp[secondRight] && sum <= temp[secondRight])
                    badPairs--;
            }

            // update the respective sum after merging 
            if(firstLeft >= 0){
                sumPairs.erase({temp[firstLeft] + temp[first], firstLeft});
                sumPairs.insert({temp[firstLeft] + sum, firstLeft});
            }

            if(secondRight < n){
                sumPairs.erase({temp[second] + temp[secondRight], second});
                sumPairs.insert({temp[secondRight] + sum, first});
                prevInd[secondRight] = first;       // update the prev index
            }
            // update the next index 
            nextInd[first] = secondRight;
            temp[first] += temp[second];
            operations++;
        }
        return operations;
    }
};
