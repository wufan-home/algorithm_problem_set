/*
  Reverse a singly linked list.
  A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        for(; head != NULL;)
        {
            ListNode *tempNode = head;
            head = head->next;
            tempNode->next = newHead;
            newHead = tempNode;
        }
        
        return newHead;
    }
};
