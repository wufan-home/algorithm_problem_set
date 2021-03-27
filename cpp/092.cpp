/*
   Reverse a linked list from position m to n. Do it in-place and in one-pass.

   For example:
   Given 1->2->3->4->5->NULL, m = 2 and n = 4,

   return 1->4->3->2->5->NULL.

   Note:
   Given m, n satisfy the following condition:
   1 ≤ m ≤ n ≤ length of list. 
*/

#include <iostream>
#include <climits>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int v) : val(v), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
	if(head == NULL || m == n)
		return head;

	ListNode *dummy = new ListNode(INT_MIN);
	dummy->next = head;
	ListNode *back = dummy;
	for(int i = 1; i < m; ++i, back = back->next) {}

	int num = n - m + 1;
	ListNode *cur = back->next;
	ListNode *temp = new ListNode(INT_MIN);
	ListNode *tail = cur;
	for(int i = 0; i < num; ++i)
	{
		ListNode *temp1 = temp->next;
		temp->next = cur;
		cur = cur->next;
		temp->next->next = temp1;
	}

	back->next = temp->next;
	tail->next = cur;
	return dummy->next;
}

int main()
{
	ListNode *head = new ListNode(INT_MIN);
	ListNode *cur = head;
	for(int i = 1; i <= 5; ++i, cur = cur->next)
		cur->next = new ListNode(i);

	head->next = reverseBetween(head->next, 1, 5);
	for(cur = head->next; cur != NULL; cur = cur->next)
		cout << cur->val << "->";
	cout << endl;
}
