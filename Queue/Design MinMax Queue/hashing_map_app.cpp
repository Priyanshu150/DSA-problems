#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N) 

// Approach :-
// we can use queue for standard queue operations 
// and ordered map for tracking min and max element in O(1) time 

//link :- https://www.geeksforgeeks.org/problems/design-minmax-queue/1

class SpecialQueue {
  private:
    queue<int> q;
    map<int,int> mp;
  
  public:
    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        mp[x] += 1;
    }

    void dequeue() {
        // Remove element from the queue
        int ele = getFront();
        q.pop();
        mp[ele] -= 1;
        if(mp[ele] == 0)
            mp.erase(ele);
    }

    int getFront() {
        // Get front element
        return q.front();
    }

    int getMin() {
        // Get minimum element
        return mp.begin() -> first;
    }

    int getMax() {
        // Get maximum element
        return mp.rbegin() -> first;
    }
};