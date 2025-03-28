#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// we can store the start time and end time of task in a array 
// sort them based on end time i.e the task that is ending first should come first 
// start by taking the first task & store the end time in variable(end) and keep cout of the task taken
// traverse in the sorted array if we find the next task having starting time greater than previouse ending time 
// then take that task increase the cnt and update the previous end time 


//Link :- https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size();
        vector<pair<int,int>> temp;
        
        for(int i=0; i<n; ++i)
            temp.push_back({start[i], finish[i]});
        
        sort(temp.begin(), temp.end(), [&](pair<int,int> &p1, pair<int,int> &p2){
            if(p2.second == p1.second)
                return p1.first < p2.first;
            
            return p1.second < p2.second;
        });
        int end = temp[0].second, tasks = 1;
        
        for(int i=1; i<n; ++i){
            if(end < temp[i].first){
                ++tasks;
                end = temp[i].second;
            }
        }
        return tasks;
    }
};
