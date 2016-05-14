#include <iostream>
#include <climits>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
};

ListNode* removeElements(ListNode* head, int val) {
	ListNode *dummy = new ListNode(INT_MIN);
    	ListNode *cur = dummy;
    	while(head)
    	{
    		ListNode *cur_ = head;
    		head = head->next;
    		if(cur_->val != val)
    		{
    			cur->next = cur_;
    			cur = cur->next;
    		}
    	}
    	cur->next = NULL;
    	return dummy->next;
}
