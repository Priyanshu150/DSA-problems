#include <bits/stdc++.h>

// Time complexity :- O(n * log(n))
// Space complexity :- O(n)

// Approach :-  
// maintain a array with difference b/w two cost of robot doing task 
// sort them based on the lower to higher difference value, except negative difference sort them by absolute value 
// pick the next x trasaction from robot A and next y transaction from robot B 

// Intution :- 
// The idea is that we should first handle the tasks where the difference between profits is highest, 
// because choosing the wrong machine for those tasks would cause the biggest loss. 
// For tasks where both machines give similar profits, it doesn’t matter much who processes them. 
// So, we greedily assign each task to the machine who gives higher profit while respecting constraints.


// Links :- https://www.geeksforgeeks.org/problems/max-profit-from-two-machines/1

class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        int n = a.size();
        vector<pair<int, pair<int,int>>> temp;
        
        // add difference b/w task cost and task cost into array 
        for(int i=0; i<n; ++i){
            int diff = (a[i] - b[i]);
            temp.push_back({diff, {a[i], b[i]}});
        }
        
        // sort the array based on the differece 
        sort(temp.begin(), temp.end(), [&](pair<int, pair<int,int>> &p1, pair<int, pair<int,int>> &p2){
            int diff1 = p1.first;
            int diff2 = p2.first;
            
            // sort the -ve diff based on higher absolute value 
            if(diff1 < 0 && diff2 < 0)
                return  diff1 < diff2;
            
            return diff1 > diff2;
        });
        
        int maxProfit = 0;
        
        for(int i=0; i<n; ++i){
            // find the different, cost of task from sorted values 
            int diff = temp[i].first;
            int cost1 = temp[i].second.first;
            int cost2 = temp[i].second.second;
            
            // +ve differen and we can make machine A work
            if(diff >= 0 && x > 0){
                maxProfit += cost1;
                x--;
            }
            // -ve differen and we can make machine B work
            else if(y > 0){
                maxProfit += cost2;
                y--;
            }
            // otherwise machine A can work 
            else{
                maxProfit += cost1;
                x--;
            }
        }
        return maxProfit;
    }
};