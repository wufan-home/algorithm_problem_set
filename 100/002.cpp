/*
  You are given two linked lists representing two non-negative numbers. 
  The digits are stored in reverse order and each of their nodes contain a single digit. 
  Add the two numbers and return it as a linked list.
  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8

  Solution: Let two pointers, each of which runs from one head of two linked-lists,
  run until both of them are NULL. 
  Build a new node by the sum of two values from the two linked-lists.
  In the end, add a new node if the overflow is 1 after the loop.
*/

#include <climits>

struct ListNode
{
	int val;
	ListNode *next;
};

using namespace std;

ListNode *addLists(ListNode *l1, ListNode *l2)
{
    if(l1 == NULL)
        return l2;

    if(l2 == NULL)
        return l1;

    ListNode *dummy = new ListNode(INT_MIN);
    ListNode *cur = dummy;
    int overflow = 0;
    for(ListNode *p1 = l1, *p2 = l2; p1 || p2 || overflow;)
    {
        int value = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + overflow;
        overflow = value / 10;
        value %= 10;
        cur->next = new ListNode(value);
        cur = cur->next;
        if(p1)
            p1 = p1->next;
        if(p2)
            p2 = p2->next;
    }

    return dummy->next;
}
