#include <iostream>

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
