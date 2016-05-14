// 147.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

ListNode* insertionSortList(ListNode* head)
{
	if (!head)
		return head;

	ListNode *r = head;
	head = head->next;
	r->next = NULL;

	for (ListNode *p_cur = head; p_cur != NULL; )
	{
		ListNode *cur = p_cur;
		p_cur = p_cur->next;
		cur->next = NULL;

		if (r->val >= cur->val)
		{
			cur->next = r;
			r = cur;
			continue;
		}

		for (ListNode *p_temp = r; ; p_temp = p_temp->next)
		{
			if (p_temp->next == NULL)
			{
				p_temp->next = cur;
				break;
			}
			else if (p_temp->next->val >= p_cur->val)
			{
				ListNode *p_temp_next = p_temp->next;
				p_temp->next = cur;
				cur->next = p_temp_next;
				break;
			}
		}
	}

	return r;
}

int main()
{
	ListNode *head = new ListNode(5);
	head->next = new ListNode(4);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(1);
	head->next->next->next->next = new ListNode(3);
	insertionSortList(head);
    return 0;
}

