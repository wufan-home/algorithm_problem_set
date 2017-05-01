/*
    Write a program to find the node at which the intersection of two singly linked lists begins.
    For example, the following two linked lists:

    A:          a1 → a2
                       ↘
                         c1 → c2 → c3
                       ↗            
    B:     b1 → b2 → b3
    begin to intersect at node c1.


    Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
            
        if(headA == headB)
            return headA;

        ListNode *curA = headA;
        for(; curA->next; curA = curA->next) {}
        ListNode *curB = headB;
        for(; curB->next; curB = curB->next) {}
        if(curA != curB)
            return NULL;
        
        ListNode *tempBTail = curB;    
        curB->next = headB;
        for(curA = headA->next, curB = headA->next->next; curA != curB; curA = curA->next, curB = curB->next->next) {}
        
        for(curA = headA; curA != curB; curA = curA->next, curB = curB->next) {}
        
        tempBTail->next = NULL;
        
        return curA;
    }
};
