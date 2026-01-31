#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(1)
//Space complexity :- O(n + k) 

// Approach :-

//link :- https://www.geeksforgeeks.org/problems/implement-k-queues-in-a-single-array/1

class kQueues {
  private:
    int n, k, freeIndex;
    vector<int> arr, front, rear, next;
  
  public:
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;
        arr.resize(n);
        front.resize(k, -1);
        rear.resize(k, -1);
        next.resize(n);
        
        // initialize all space as free 
        freeIndex = 0;
        for(int i=0; i<n-1; ++i)
            next[i] = i+1;
        
        // -1 is used to indicate end of free list 
        next[n-1] = -1;
    }

    void enqueue(int x, int i) {
        if(isFull())
            return;
        
        // get next free index
        int ind = freeIndex;
        freeIndex = next[ind];
        
        // if queue if empty, update both front and rear 
        if(isEmpty(i)){
            front[i] = ind;
        }
        else{
            // link new element to the previous rear 
            next[rear[i]] = ind;
        }
        // update rear 
        rear[i] = ind;
        // store the element 
        arr[ind] = x;
        // mark end of queue
        next[ind] = -1;
    }

    int dequeue(int i) {
        // check if queue is empty
        if(isEmpty(i))
            return -1;
        
        // get the front index of queue
        int ind = front[i];
        
        // update front
        front[i] = next[ind];
        
        // queue becomes empty
        if(front[i] == -1)
            rear[i] = -1;
        
        // add the dequeued position of free list 
        next[ind] = freeIndex;
        freeIndex = ind;
        
        // return the dequeued element 
        return arr[ind];
    }

    bool isEmpty(int i) {
        return (front[i] == -1);
    }

    bool isFull() {
        return (freeIndex == -1);
    }
};
