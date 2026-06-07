#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(level)
// Space complexity :- O(1)

// Approach :- 
// from every node find the information about parent node
// using that deduce the current node's profession 

// Link :- https://www.geeksforgeeks.org/problems/finding-profession3834/1

class Solution {
  private:
    string solve(int level, int pos){
        if(level == 1 && pos == 1){
            return "Engineer";
        }
        
        string val = solve(level-1, (pos+1)/2);
        
        if((pos%2 && val == "Doctor") || (pos%2 == 0 && val == "Engineer"))
            return "Doctor";
        
        return "Engineer";
    }
  
  public:
    string profession(int level, int pos) {
        return solve(level, pos);
    }
};
