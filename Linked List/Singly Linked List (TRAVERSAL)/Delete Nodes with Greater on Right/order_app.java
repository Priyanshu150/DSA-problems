import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(1)

// Approach :- 
// reverse the list 
// maintain a ascending order of list 
// as last node always exists in our answer 
// then again reverse the list to get our answer 

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
    private Node reverse(Node head){
        Node curr = head;
        Node prev = null;
        Node nex = null;
        
        while(curr != null){
            nex = curr.next;
            // reverse the link 
            curr.next = prev;
            // update the link to point to the next address 
            prev = curr;
            curr = nex;
        }
        
        return prev;
    }
    
    Node compute(Node head) {
        // base case
        if(head == null || head.next == null)    
            return head;
        
        // reverse the current list 
        Node newHead = reverse(head);
        
        Node curr = newHead;
        Node maxNode = newHead;
        
        // maintain a ascending order list 
        while(curr != null && curr.next != null){
            // current node is smaller than maximum node 
            // delete the node 
            if(curr.next.data < maxNode.data){
                curr.next = curr.next.next;
            }
            // update the max node address 
            else{
                curr = curr.next;
                maxNode = curr;
            }
        }
        
        // reverse the answer list
        return reverse(newHead);
    }
}