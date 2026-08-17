import java.util.*;

//Time complextiy :- O(n^2)
// Space complexity :- O(n^2)

// Approach :-  
// Hash the details of snake and ladder 
// use bfs to find the shortest path using level order traversal


// links :- https://www.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1

class Solution {
    public int minThrows(int n, int[] lad, int[] sn) {
        int n1 = lad.length;
        HashMap<Integer, Integer> ladder = new HashMap<>();
        for(int i = 0; i < n1; i += 2)
            ladder.put(lad[i], lad[i+1]);

        int n2 = sn.length;
        HashMap<Integer, Integer> snake = new HashMap<>();
        for(int i = 0; i < n2; i += 2)   
            snake.put(sn[i], sn[i+1]);

        Queue<Integer> q = new LinkedList<>();  
        Set<Integer> vis = new HashSet<>();     
        q.offer(1);
        vis.add(1);

        int moves = 0;   

        while(!q.isEmpty()) {
            int sz = q.size();

            while(sz-- > 0) {
                int value = q.poll();   

                if(value >= (n * n))
                    return moves;

                for(int next = 1; next <= 6; ++next) {
                    int nextValue = value + next;
                    if(nextValue > n * n) break;

                    if(ladder.containsKey(nextValue))
                        nextValue = ladder.get(nextValue);
                    else if(snake.containsKey(nextValue))
                        nextValue = snake.get(nextValue);

                    if(!vis.contains(nextValue)) {
                        vis.add(nextValue);
                        q.offer(nextValue);           
                    }
                }
            }
            ++moves;
        }
        return -1;
    }
}