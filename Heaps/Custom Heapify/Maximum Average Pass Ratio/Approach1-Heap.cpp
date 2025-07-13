#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    #define pdi pair<double,int>

    void heapPush(priority_queue<pdi>& maxHeap, vector<vector<int>>& classes, int ind){
        double curr_avg = (double)classes[ind][0] / classes[ind][1];
        double new_avg = ((double)classes[ind][0]+1) / (classes[ind][1]+1);
        double possible_increment = new_avg - curr_avg;
        maxHeap.push(make_pair(possible_increment, ind));
    }

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pdi> maxHeap;

        for(int i=0; i<n; ++i)
            heapPush(maxHeap, classes, i);
        
        while(extraStudents--){
            int ind = maxHeap.top().second;
            maxHeap.pop();

            classes[ind][0] += 1;
            classes[ind][1] += 1;

            heapPush(maxHeap, classes, ind);
        }
        double avg = 0;
        for(int i=0; i<n; ++i)
            avg += (double)classes[i][0]/classes[i][1];
        
        return avg/n;
    }
};