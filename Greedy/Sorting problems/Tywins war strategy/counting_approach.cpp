#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*log(n))
//Space complexity :- O(n)

// Approach :-
// traverse the array and count the number of number already satify the condition 
// and for rest push find the deficit number and push them into a min heap 
// if our cnt is less than n/2 then take the rest of element from the heap 

//link :- https://www.geeksforgeeks.org/problems/tywins-war-strategy0527/1

class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), cnt = 0, res = 0;
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(int i=0; i<n; ++i){
            if(arr[i]%k == 0)
                cnt++;
            else 
                pq.push(k - arr[i]%k);
        }
        
        while(cnt < (n+1)/2){
            res += pq.top();
            pq.pop();
            cnt++;
        }
        return res;
    }
};