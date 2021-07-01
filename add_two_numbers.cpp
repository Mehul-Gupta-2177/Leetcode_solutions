/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Time Compelxity = O(n,m) -> as we go through l1 and l2 both until the end of one of them so max of any of them
// Space Complexity = O(n,m) -> as we go through l1 and l2 both until the end of one of them while creating a new liist and not modifying others,
// where each node corresponds to new node.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
       // creates a new head for the Linked List 
       ListNode* head = new ListNode(0);
       // sets the current node to be traversed as head
       ListNode* current = head; 
       // 
       int carry = 0;
       int sum = 0;
        // sets the condition to traverse through the entire LL
        while(l1 != NULL || l2 != NULL){
            // get the 2 values
            int a = (l1 != NULL) ? l1->val : 0;
            int b = (l2 != NULL) ? l2 ->val : 0;
            // adds the two sums and if any carry is there
            sum = a + b + carry;
            carry = sum/10;
            // gets the remainder and puts it in the value
            current->val = sum % 10;
            // goes to the next value
            if ( l1 != NULL) l1 = l1->next;
            if ( l2 != NULL) l2 = l2->next;
            
            // creates a new node to input the value
            if(l1 != NULL || l2 != NULL){
               current->next = new ListNode(0);
                current = current->next;
            }
            
        }
        // checks if therre is any left over carry value
        if(carry != 0){
        
            current->next =  new ListNode(carry);
            
        }
        
        return head;
    }
};
