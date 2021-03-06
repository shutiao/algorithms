/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // create dummy node to normailze the process, ensure node->next never be null.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* node = dummy;
        
        // main function, always stands on a valid node and check the followeing 2 nodes. ends when there are less 2.
        while(node->next!=NULL && node->next->next!=NULL){
            // flag the duplicate, record the value and delete one by one.
            if(node->next->val == node->next->next->val){
                int val = node->next->val;
                // delete next node
                while(node->next!=NULL && node->next->val == val){
                    ListNode* toDelete = node->next;
                    node->next = node->next->next;
                    delete toDelete;
                }
            }
            else{
                node = node->next;
            }
        }
        
        // always return dummy->head when there is dummy
        return dummy->next;
    }
};