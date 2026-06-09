import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(n)

// Approach :- 
// use recursion to solve the sub-problem, which will return the list as per our requirement 
// we've to just merge two node 
// if current node value is greater than other one then merge them 
// otherwise delete the first node and remaining list will be our answer 

// Link :- https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

class Node {

    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class Solution {
    Node compute(Node head) {
        if(head == null || head.next == null){
            return head;
        }
        // find the address of list sorted in the descending order 
        Node nextNode = compute(head.next);
        // if next list data is greater than current 
        if(head.data < nextNode.data){
            return nextNode;   
        }
        // update the link of head 
        head.next = nextNode;
        return head;
    }
}