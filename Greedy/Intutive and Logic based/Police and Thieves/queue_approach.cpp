#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :- 
// maintain the index of theives in the queue 
// for every police try to find the closest theif 
// if the theif on the left side is out of range remove it from the queue 
// because no police can reach it if leftmost police can't reach it 
// otherwise check the front of queue if it's within the range of the police remove it
// and count the contribution as answer


// Link :- https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1

class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n = arr.size(), res = 0;
        queue<int> q;
        
        for(int i=0; i<n; ++i){
            if(arr[i] == 'T'){
                q.push(i);
            }
        }
        for(int i=0; i<n; ++i){
            if(arr[i] == 'P'){
                while(!q.empty() && (i - q.front()) > k)
                    q.pop();
                    
                if(!q.empty() && abs(i - q.front()) <= k){
                    q.pop();
                    res++;
                }
            }
        }
        return res;
    }
};

class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size(), res = 0;
        queue<int> police, thieves;
        
        for(int i=0; i<n; ++i){
            // push police and thieves into their respective queues
            if(arr[i] == 'P')
                police.push(i);
            else 
                thieves.push(i);
            
            // process the thieves and police 
            while(!police.empty() && !thieves.empty()){
                // theif and policeman are in range 
                if(abs(police.front() - thieves.front()) <= k){
                    res++;
                    thieves.pop();
                    police.pop();
                }
                // they are out of range 
                else if(police.front() < thieves.front())
                    police.pop();
                else 
                    thieves.pop();
            } 
        }
        return res;
    }
};