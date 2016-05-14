#include <iostream>

using namespace std;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(INT_MIN);
	ListNode *cur = dummy;
	while(l1 != NULL || l2 != NULL)
	{
		ListNode *next = ((l1 == NULL ? INT_MAX : l1->val) <=
				  (l2 == NULL ? INT_MAX : l2->val) ?
				  l1 : l2);
		cur->next = next;
		cur = cur->next;
		next == l1 ? l1 = l1->next : l2 = l2->next;
	}
	return dummy->next;
}

int main()
{
	return 1;
}
