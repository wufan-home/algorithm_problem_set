// 138.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
	if (head == NULL)
		return NULL;

	for (RandomListNode *p_cur = head; p_cur != NULL;)
	{
		RandomListNode *temp = p_cur->next;
		p_cur->next = new RandomListNode(p_cur->label);
		p_cur->next->next = temp;
		p_cur = temp;
	}

	for (RandomListNode *p_cur = head; p_cur != NULL; p_cur = p_cur->next->next)
	{
		if(p_cur->random)
			p_cur->next->random = p_cur->random->next;
	}

	RandomListNode *r = head->next;
	for (RandomListNode *p_cur = r; p_cur->next != NULL;
	p_cur->next = p_cur->next->next, p_cur = p_cur->next) {
	}

	return r;

}

int main()
{
	RandomListNode *head = new RandomListNode(-1);
	RandomListNode * r = copyRandomList(head);
    return 0;
}

