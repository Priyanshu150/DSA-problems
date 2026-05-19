import java.util.*

// Time complexity :- O((end-start)*n)
// Space complexity :- O(end-start)

// Approach :- 
// we'll use level order / bfs traversal and begin with start value 
// and the minimum step to reach end will be our answer 

// Links :- https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

class Solution {
    public int minSteps(int[] arr, int start, int end) {
        int n = arr.length;
        int mod = 1000;
        
        Queue<Integer> q = new LinkedList<>();
        Set<Integer> vis = new HashSet<>();
        
        // initially we begin at start 
        q.offer(start);
        vis.add(start);
        int dist = 0;
        
        // level order traversal 
        while(!q.isEmpty()){
            int sz = q.size();
            
            // traverse by level 
            while(sz-- > 0){
                int val = q.poll();
                
                // reached the end 
                if(val == end)
                    return dist;
                
                for(int i=0; i<n; ++i){
                    // calcualte the next value based on current one 
                    int newVal = (arr[i]*val) % mod;
                    
                    // new value does not exists in the queue 
                    if(!vis.contains(newVal)){
                        q.offer(newVal);
                        vis.add(newVal);
                    }
                }
            }
            ++dist;
        }
        return -1;
    }
}