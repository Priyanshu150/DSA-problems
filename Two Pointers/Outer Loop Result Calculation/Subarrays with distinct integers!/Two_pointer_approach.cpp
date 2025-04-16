#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N + N)   
//Space complexity :- O(1)

//Approach :- 
// To directly count the subarrays with exactly B different integers is hard but 
//to find the count of subarrays with at most B different integers is easy.
// Equal_To_B = at_Most_B - at_Most_B-1

//Link :- https://www.interviewbit.com/problems/subarrays-with-distinct-integers/

int atMostB(vector<int> &arr, int target, int &n){
    int i(0), j(0), res(0);
    unordered_map<int,int> freq;
    
    while(j < n){
        freq[arr[j]] += 1;
        
        while(freq.size() > target && i < j){
            freq[arr[i]] -= 1;
            if(freq[arr[i]] == 0)
                freq.erase(arr[i]);
            
            i++;
        }
        res += (j - i + 1);
        j++;
    }
    return res;
}

int solve(vector<int> &A, int B) {
    int n = A.size();
    if(B == 1)
        return atMostB(A, B, n);
        
    return atMostB(A, B, n) - atMostB(A, B-1, n);
}