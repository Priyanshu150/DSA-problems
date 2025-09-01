#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(1)

// Approach :- 
// Pay attention to how much the pass ratio changes when you add a student to the class. 
// If you keep adding students, what happens to the change in pass ratio?
// The more students you add to a class, the smaller the change in pass ratio becomes.
// Since the change in the pass ratio is always decreasing with the more students you add, 
// then the very first student you add to each class is the one that makes the biggest change in the pass ratio
// Because each class's pass ratio is weighted equally, it's always optimal to put the student in the class that makes the biggest change among all the other classes.
// Keep a max heap of the current class sizes and order them by the change in pass ratio. 
// For each extra student, take the top of the heap, update the class size and put it back in the heap.

//Link :-  https://leetcode.com/problems/maximum-average-pass-ratio/

class Solution {
private:
    #define pdi pair<double,int>

    void heapPush(priority_queue<pdi> &maxHeap, int ind, vector<vector<int>>& classes){
        int student = classes[ind][0], totalStudent = classes[ind][1];
        double avg = (double)student / totalStudent;
        double new_avg = (double)(student + 1) / (totalStudent + 1);
        maxHeap.push({new_avg - avg, ind});
    }

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pdi> maxHeap;

        for(int ind=0; ind<n; ++ind)
            heapPush(maxHeap, ind, classes);
        
        while(extraStudents--){
            int ind = maxHeap.top().second;
            maxHeap.pop();

            classes[ind][0] += 1;
            classes[ind][1] += 1;

            heapPush(maxHeap, ind, classes);
        }
        double res = 0.0;
        for(int ind=0; ind<n; ++ind){
            res += (double)(classes[ind][0]) / (classes[ind][1]);
        }
        return res/n;
    }
};