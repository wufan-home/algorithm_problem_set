/*
	Given a sorted linked list, delete all duplicates such that each element appear only once.

	For example,
	Given 1->1->2, return 1->2.
	Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode *removedHead = NULL;
        ListNode *curNode = NULL;
        while(head != NULL)
        {
            ListNode *temp = head->next;
            if(curNode == NULL || head->val > curNode->val)
            {
                if(removedHead == NULL)
                {
                    removedHead = head;
                    curNode = head;
                }
                else
                {
                    curNode->next = head;
                    curNode = curNode->next;
                }
                
                curNode->next = NULL;
            }
            else
                delete head;
                
            head = temp;
        }
        
        return removedHead;
    }
};
