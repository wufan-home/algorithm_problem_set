/*
  Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
  If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
  You may not alter the values in the nodes, only nodes itself may be changed.
  Only constant memory is allowed.
  For example,
  Given this linked list: 1->2->3->4->5
  For k = 2, you should return: 2->1->4->3->5
  For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        for(ListNode *cur = head; cur != NULL; cur = cur->next, ++size) {}
        
        if(size == 0 || k > size || k == 1)
            return head;

        ListNode *newHead = NULL;
        ListNode *tail = NULL;
        for(ListNode *cur = head; cur != NULL;)
        {
            ListNode *localHead = cur;
            int i = 1;
            for(; i < k && cur->next != NULL; ++i)
                cur = cur->next;

            if(i < k)
            {
                tail->next = localHead;
                break;
            }

            ListNode *temp = cur->next;
            cur->next = NULL;
            cur = temp;
            
            if(tail == NULL)
                newHead = reverseList(localHead);
            else
                tail->next = reverseList(localHead);
                
            tail = localHead;
        }
        
        return newHead;
    }
    
private:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *newHead = NULL;
        while(head)
        {
            ListNode *temp = head;
            head = head->next;
            temp->next = newHead;
            newHead = temp;
        }
        return newHead;
    }
};
