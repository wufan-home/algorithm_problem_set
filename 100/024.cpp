// 24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct ListNode
{
	ListNode(int val) : val(val), next(NULL) {}
	int val;
	ListNode *next;
} ListNode;

ListNode* swapPairs(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *result = NULL;
	ListNode *p_cur = NULL;
	while (head != NULL)
	{
		if (head->next == NULL)
		{
			p_cur->next = head;
			head = NULL;
		}
		else
		{
			ListNode *temp = head;
			head = head->next->next;
			if (result == NULL)
			{
				result = temp->next;
				p_cur = temp->next;
			}
			else
			{
				p_cur->next = temp->next;
				p_cur = p_cur->next;
			}

			p_cur->next = temp;
			p_cur = temp;
		}
	}

	return result;
}

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head = swapPairs(head);
	while (head != NULL) 
	{
		cout << head->val << ", ";
		head = head->next;
	}
    return 0;
}

