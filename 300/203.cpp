/*
  Remove all elements from a linked list of integers that have value val.
  Example
  Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
  Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newHead = NULL;
        ListNode *curNode = NULL;
        while(head != NULL)
        {
            ListNode *tempNode = head;
            head = head->next;
            
            if(tempNode->val == val)
                delete tempNode;
            else
            {
                if(newHead == NULL)
                {
                    newHead = tempNode;
                    curNode = tempNode;
                }
                else
                {
                    curNode->next = tempNode;
                    curNode = curNode->next;
                }
                curNode->next = NULL;
            }
        }
        
        return newHead;
    }
};
