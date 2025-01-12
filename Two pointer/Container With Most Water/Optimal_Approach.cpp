#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       
//Space complexity :- O(1)    

//Approach :-
// Formula to calulate the volume will be min(arr[i], arr[j])*(j-i), where j > i
// start with extreme right and left pointer 
// And increase the pointer from that end which has smaller height
// Becuase as long as that height is included the height of line remain will be small 
// And once increasing the pointere there will be chance of finding new height 

//link :- https://www.interviewbit.com/problems/container-with-most-water/

int maxArea(vector<int> &arr) {
    int n = arr.size(), st = 0, end = n-1, res = 0;
    
    while(st < end){
        int area = min(arr[st], arr[end]) * (end - st);
        res = max(area, res);
        if(arr[st] < arr[end])      st++;
        else    end--;
    }
    return res;
}