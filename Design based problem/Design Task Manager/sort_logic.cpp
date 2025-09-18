#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(N)

// Approach :-  
// We'll use one set to keep track of highest priority task in form of {-priority, -taskId}
// And more ds we'll use to store the map of taskId -> {priority, userId}

// In Constructor TaskManager, we'll store all the give task in the format
// In add function, we'll remove the task in the same format
// In edit function, we'll first remove the previous task and add the new one with give priority
// In remove function, we'll erase the task from both ds 
// In execTop function, we'll find the first task from set if it's not empty and delete the task 
//                  and return the userId of task which we can fetch from the mapping 

// links :- https://leetcode.com/problems/design-task-manager/

class TaskManager {
private:
    #define pi pair<int,int> 
    set<pi> priorityTask; // stores { -priority, -taskId }
    unordered_map<int, pi> taskInfo; // taskId -> {priority, userId}

public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task: tasks){
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];

            // insert a task into the ds
            priorityTask.insert({-priority, -taskId});
            taskInfo[taskId] = {priority, userId};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        // insert a task 
        priorityTask.insert({-priority, -taskId});
        taskInfo[taskId] = {priority, userId};
    }
    
    void edit(int taskId, int newPriority) {
        // find previous information related to taskId
        int userId = taskInfo[taskId].second;
        // remove the previous records relate to taskId
        rmv(taskId);
        // add the new priority to the taskId
        add(userId, taskId, newPriority);
    }
    
    void rmv(int taskId) {
        // find previous information related to taskId
        int prevPriority = taskInfo[taskId].first;

         // remove the previous records relate to taskId
        priorityTask.erase({-prevPriority, -taskId});
        taskInfo.erase(taskId);
    }
    
    int execTop() {
        // check if any task in present in the list or not 
        if(priorityTask.empty())
            return -1;
        
        // find the task with top most priority 
        auto [negPriority, negTaskId] = *priorityTask.begin();
        int taskId = -negTaskId;
        int userId = taskInfo[taskId].second;

        // remove the task from the list
        rmv(taskId);
        return userId;
    }   
};


/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */