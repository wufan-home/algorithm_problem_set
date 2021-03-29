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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l1;
        
        ListNode *head = l1;
        int overflow = 0;
        for(ListNode *cur = l1; ; cur = cur->next)
        {
            int result = (l1 != NULL ? l1->val : 0) + 
                (l2 != NULL ? l2->val : 0) + overflow;
            
            overflow = result / 10;
            result %= 10;
            cur->val = result;
            
            l1 = l1 != NULL ? l1->next : NULL;
            l2 = l2 != NULL ? l2->next : NULL;
            if(l1 == NULL && l2 == NULL)
            {
                if(overflow)
                    cur->next = new ListNode(overflow);
                
                break;
            }
            
            cur->next = new ListNode(0);
        }
        
        return head;
    }
};
