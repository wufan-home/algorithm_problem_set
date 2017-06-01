/*
    Given a sorted linked list, delete all nodes that have duplicate numbers, 
    leaving only distinct numbers from the original list.

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
    Solution() : removedHead(NULL), tail(NULL) {}
    
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        removedHead = NULL;
        tail = NULL;
        for(; head != NULL;)
        {
            if(head ->next == NULL || head->val != head->next->val)
            {
                ListNode *temp = head->next;
                addEligibleNodes(head);
                head = temp;
            }
            else
            {
                int value = head->val;
                while(head != NULL && value == head->val)
                {
                    ListNode *temp = head->next;
                    delete head;
                    head = temp;
                }
            }
        }
        
        return removedHead;
    }
    
private:
    void addEligibleNodes(ListNode *node)
    {
        if(removedHead == NULL)
        {
            removedHead = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        
        tail->next = NULL;
    }
    
    ListNode *removedHead;
    ListNode *tail;
};
