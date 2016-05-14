#include <iostream>
#include <climits>

using namespace std;

struct ListNode
{
	ListNode(int v) : val(v), next(NULL) {}

	int val;
	ListNode *next;
};

ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
		return head;

	int total = 0;
	for(ListNode *front = head;
	    front != NULL;
	    front = front->next, ++total) {}
	if(k > total)
		return head;

	ListNode *dummy = new ListNode(INT_MIN);
	ListNode *cur = dummy;
	for(ListNode *front = head; front != NULL;)
	{	
		ListNode *new_tail = NULL;
		for(int i = 0; i < k; ++i)
		{
			if(front == NULL)
				break;

			ListNode *temp = front;
			front = front->next;
			if(cur->next == NULL)
			{
				new_tail = temp;
				new_tail->next = NULL;
				cur->next = temp;
			}
			else
			{
				
				ListNode *temp_next = cur->next;
				cur->next = temp;
				temp->next = temp_next;
			}
		}
		cur = new_tail;
		total -= k;
		if(total < k)
		{
			cur->next = front;
			break;
		}
	}

	return dummy->next;
}

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *cur = head;
	for(int i = 2; i <= 11; ++i, cur = cur->next)
		cur->next = new ListNode(i);

	for(cur = head; cur != NULL; cur = cur->next)
		cout << cur->val << "->";
	cout << endl;
	head = reverseKGroup(head, 3);
	for(cur = head; cur != NULL; cur = cur->next)
		cout << cur->val << "->";
	cout << endl;
	return 1;
}
