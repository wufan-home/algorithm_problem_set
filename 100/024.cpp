/*
  Given a linked list, swap every two adjacent nodes and return its head.
  For example,
  Given 1->2->3->4, you should return the list as 2->1->4->3.
  Your algorithm should use only constant space. 
  You may not modify the values in the list, only nodes itself can be changed.
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *newHead = NULL;
        ListNode *cur = NULL;
        
        if(head == NULL || head->next == NULL)
            return head;
            
        for(ListNode *back = head, *front = head->next; ;)
        {
            ListNode *tempHead = front->next;
            front->next = back;
            back->next = NULL;
            if(newHead == NULL)
            {
                cur = front;
                newHead = cur;
            }
            else
            {
                cur->next = front;
                cur = cur->next;
            }
            cur = cur->next;
            
            if(tempHead == NULL || tempHead->next == NULL)
            {
                cur->next = tempHead;
                break;
            }
            
            back = tempHead;
            front = back->next;
        }
        
        return newHead;
    }
};
