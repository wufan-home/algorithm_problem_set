#include <iostream>
#include <vector>

using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *temp_head = new ListNode(INT_MIN);
	temp_head->next = head;

	Listnode *back = temp_head;
	ListNode *front = head;
        for(int i = 0; i < n; ++i)
		front = front->next;

	while(front != NULL)
	{
		back = back->next;
		front = front->next;
	}

	back->next = back->next->next;
	return temp_head->next;
}

int main()
{
	return 1;
}
