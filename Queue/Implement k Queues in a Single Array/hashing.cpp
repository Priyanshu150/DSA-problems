#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(1)
//Space complexity :- O(n + k) 

// Approach :-
// use 4 array to store the information of the queues 
// and a freeInd which denotes which is the free index current
// arr :- keep the element in this 
// front & rear array :- keep track of index where front and rear index of each queue appears
// next :- track the next avialble index and the element index of particular queue which are 
//      not front or rear element, -1 indicated the end of queue 

// Algorithm :- 
// isEmpty(qn) => front[qn] is -1, then it's empty
// isFull() => freeInd is -1, then array is full

// enQueue(qn, ele) => 
// check if array is full or not ?? If not then 
// ind = freeInd and update new freeInd
// if first time insertion then update front[qn] and rear[qn] with -1
// if not then next[rear[qn]] = ind, represent a chain of element and also help in backtracking
// arr[ind] equals element and next[ind] = -1, to mark the end 

// deQueue(qn) => 
// check if queue is already empty or not ?? if not then 
// find first index of qn used front array, ind = front[qn]
// using next find the wheather the next element is present in the queue or not 
// if not update both front[qn] & rear[qn]  with -1
// update the pointers, next[ind] = freeInd and freeInd = ind 

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
