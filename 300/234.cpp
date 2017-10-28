/*
    Given a singly linked list, determine if it is a palindrome.

    Follow up:
    Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        
        int count = 0;
        for(ListNode *cur = head; cur != NULL; cur = cur->next)
            ++count;
        
        int half = count / 2;
        ListNode *first = revert(head, half);
        ListNode *second = head;
        if(count % 2 == 1)
            second = second->next;
        
        for(ListNode *cur1 = first, *cur2 = second; cur1 != NULL; cur1 = cur1->next, cur2 = cur2->next)
        {
            if(cur1->val != cur2->val)
                return false;
        }
        
        return true;
    }
    
private:
    ListNode *revert(ListNode *&head, int size)
    {
        ListNode *res = NULL;
        for(; size > 0; --size)
        {
            ListNode *temp = head;
            head = head->next;
            
            if(res == NULL)
            {
                res = temp;
                temp->next = NULL;
            }
            else
            {
                ListNode *temp1 = res;
                res = temp;
                res->next = temp1;
            }
        }
        return res;
    }
};
