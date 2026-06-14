import java.util.*;

// Time complextiy :- O(N)
// Space complexity :- O(N)

// Approach :-   
// the car that is moving left will go left until it find a car in rest or car moving right 
// the car that is moving right will go right until it find a car in rest or car moving left
// hence we've to keep track of all the previous car movement, we'll use 'Stack'
// for every left moving car, if we found a car moving right => then add 2 in answer make car stationary in stack
// if we found it stationar car => then add 1 to answer noting has to be pushed into stack as a statinary car is present already
// if we find right moving car => blindly insert that into stack, no collision as we are moving left to right
// if we find staying car => only right moving car will collide with it 
// check if the previous car is right moving, then a collision will happen add 1 to answer, nothing to be pushed in stack
// at last after all the traversal, if there is any staying car on right side of right moving car 
// then we've to add those into our answer also

//Link :- https://leetcode.com/problems/count-collisions-on-a-road/description/

class Solution {
    public int countCollisions(String directions) {
        int res = 0;
        Stack<Character> st = new Stack<>();

        for(char ch: directions.toCharArray()){
            // car dir is moving left
            if(ch == 'L'){
                // no prev car found, then left moving car will keep moving without collision
                if(st.empty())  continue;
                
                char prev = st.peek();
                // collision of car both moving in opp dir
                if(prev == 'R'){
                    st.pop();
                    st.push('S');
                    res += 2;
                }
                // collsion of car when one is moving left and other is staying
                else if(prev == 'S'){
                    res += 1;
                }
            }
            // car is in rest 
            else if(ch == 'S'){
                // previous car was moving right will collide with staying car 
                if(!st.empty() && st.peek() == 'R'){
                    st.pop();
                    st.push('S');
                    res += 1;
                }
                else{
                    st.push('S');
                }
            }
            // car is moving right 
            else    st.push(ch);
        }
        char prev = 'R';        // keep track of previous moving car 

        // rest of the car moving right will collide with stationary car 
        while(!st.empty()){
            char ch = st.peek();
            st.pop();

            // right moving car colliding with previous stationary car 
            if(ch == 'R' && prev == 'S'){
                res += 1;
                prev = 'S';     // right moving car comes into stationary mode 
            }
            else    prev = ch;     // update the previous car state 
        }

        return res;
    }
}