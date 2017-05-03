/*
  You are given two linked lists representing two non-negative numbers. 
  The digits are stored in reverse order and each of their nodes contain a single digit. 
  Add the two numbers and return it as a linked list.
  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8

  Solution: Let two pointers, each of which runs from one head of two linked-lists,
  run until both of them are NULL. 
  Build a new node by the sum of two values from the two linked-lists and add it to a new linked-list.
  In the end, add a new node to the new linked-list, if the overflow is 1 after the loop. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sum_head = NULL;
        ListNode *sum_current = NULL;
        ListNode *current = NULL;
        int overflow = 0;
        while(l1 || l2)
        {
            int sum = overflow + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            overflow = sum / 10;
            sum %= 10;
            
            current = l1 ? l1 : l2;
            current->val = sum;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
            current->next = NULL;
            
            if(sum_current == NULL)
            {
                sum_current = current;
                sum_head = sum_current;
            }
            else
            {
                sum_current->next = current;
                sum_current = current;
            }
        }
        
        if(overflow)
            sum_current->next = new ListNode(overflow);
        
        return sum_head;
    }
