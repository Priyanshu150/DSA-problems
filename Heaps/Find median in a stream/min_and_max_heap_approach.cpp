#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-   
// we will maintain max_heap and min_heap and keep pushing the incoming numbers 
// the idea is that whenever there is odd number, the median will be top element of max_heap
// and whenever there is even number, the median will be mean of top element of max_heap & min_heap
// We'll maintain the order that first n element of sorted array will be in max_heap
// and the last m element of sorted array will be in min_heap
// where m+n = total number of element
// first element push it into max_heap 
// whenever odd number of element comes in, push in min_heap and top will have smallest element 
// pop that out and push eventually int0 max_heap and vice-versa

// Link :- https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

class Solution {
    public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        int n = arr.size();
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int> > min_heap;
        vector<double> ans;
        
        for(int i=0; i<n; ++i){
            double res = 0;
            if(i%2 == 0){
                if(max_heap.empty())
                    max_heap.push(arr[i]);
                else{
                    min_heap.push(arr[i]);
                    int smallest = min_heap.top();
                    min_heap.pop();
                    max_heap.push(smallest);
                }
                res = (double)max_heap.top();
            }
            else{
                max_heap.push(arr[i]);
                int largest = max_heap.top();
                max_heap.pop();
                min_heap.push(largest);
                
                double first = (double)min_heap.top(), second = (double)max_heap.top();
                res = (first + second)/2.0;
            }
            ans.push_back(res);
        }
        return ans;
    }
};