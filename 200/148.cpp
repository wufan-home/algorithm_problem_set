/*
    Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode* sortList(ListNode* head) {
        int size = 0;
        for(ListNode *cur = head; cur != NULL; cur = cur->next, ++size) {}
        
        return sortListBySize(head, size);
    }
    
private:
    ListNode* sortListBySize(ListNode *head, int size)
    {
        if(size <= 1)
            return head;
        
        const int firstHalfSize = size / 2;
        ListNode *firstHalfEnd = head;
        for(int i = 1; i < firstHalfSize; ++i, firstHalfEnd = firstHalfEnd->next) {}
        
        ListNode *secondHalfHead = firstHalfEnd->next;
        firstHalfEnd->next = NULL;
        
        ListNode *firstSortedListHead = sortListBySize(head, firstHalfSize);
        ListNode *secondSortedListHead = sortListBySize(secondHalfHead, size - firstHalfSize);
        
        return mergeTwoLists(firstSortedListHead, secondSortedListHead);
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *mergedListHead = NULL;
        ListNode *curNode = NULL;
        while(l1 || l2)
        {
            ListNode *tempCurNode = l1 ? (l2 ? (l1->val <= l2->val ? l1 : l2) : l1) : l2;
            if(tempCurNode == l1)
                l1 = l1->next;
            else
                l2 = l2->next;
            
            tempCurNode->next = NULL;
            
            if(curNode == NULL)
            {
                curNode = tempCurNode;
                mergedListHead = curNode;
            }
            else
            {
                curNode->next = tempCurNode;
                curNode = curNode->next;
            }
        }
        
        return mergedListHead;
    }
};
