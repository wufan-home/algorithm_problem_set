/*
    Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

    You should preserve the original relative order of the nodes in each of the two partitions.

    For example,
    Given 1->4->3->2->5->2 and x = 3,
    return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *smallerHead = NULL;
        ListNode *smallerTail = NULL;
        
        ListNode *otherHead = NULL;
        ListNode *otherTail = NULL;
        
        while(head != NULL)
        {
            ListNode *temp = head->next;
            if(head->val < x)
                addNodeToList(head, smallerHead, smallerTail);
            else
                addNodeToList(head, otherHead, otherTail);
            head = temp;
        }
        
        if(smallerHead == NULL)
            return otherHead;
        
        smallerTail->next = otherHead;
        return smallerHead;
    }
    
private:
    void addNodeToList(ListNode *curNode, ListNode *&listHead, ListNode *&listTail)
    {
        if(listHead == NULL)
        {
            listHead = curNode;
            listTail = curNode;
        }
        else
        {
            listTail->next = curNode;
            listTail = listTail->next;
        }
        listTail->next = NULL;
    }
};
