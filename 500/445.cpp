/*
    You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Follow up:
    What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

    Example:

    Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 8 -> 0 -> 7
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
            return l2;
        
        if(l2 == NULL)
            return l1;
        
        ListNode *rl1 = reverse(l1);
        ListNode *rl2 = reverse(l2);
        
        ListNode *addition = NULL;
        ListNode *cur = NULL;
        int overflow = 0;
        for(ListNode *cur1 = rl1, *cur2 = rl2; cur1 || cur2;)
        {
            int sum = (cur1 != NULL ? cur1->val : 0) + (cur2 != NULL ? cur2->val : 0) + overflow;
            overflow = sum / 10;
            sum %= 10;
            if(cur == NULL)
            {
                addition = new ListNode(sum);
                cur = addition;
            }
            else
            {
                cur->next = new ListNode(sum);
                cur = cur->next;
            }
            
            if(cur1)
                cur1 = cur1->next;
            
            if(cur2)
                cur2 = cur2->next;
        }
        
        if(overflow)
            cur->next = new ListNode(overflow);
    
        addition = reverse(addition);
        
        return addition;
    }
    
private:
    ListNode *reverse(ListNode *l)
    {
        ListNode *head = NULL;
        for(; l != NULL;)
        {
            ListNode *tempNode = l;
            l = l->next;
            tempNode->next = NULL;
            if(head == NULL)
            {
                head = tempNode;
            }
            else
            {
                ListNode *temp = head;
                head = tempNode;
                head->next = temp;
            }
        }
        return head;
    }
};
