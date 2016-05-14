#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct ListNode
{
	ListNode(int v) : val(v), next(NULL) {}
	int val;
	ListNode *next;
};


ListNode *MergeTwoLists(ListNode *l1, ListNode *l2)
{
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

ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
		return NULL;

	if(lists.size() == 1)
		return lists[0];

	for(int i = 1; i < lists.size(); i *= 2)
	{
		for(int j = 0; j + i < lists.size(); j += 2 * i)
			lists[j] = MergeTwoLists(lists[j], lists[j + i]);
	}

	return lists[0];
}

int main()
{
	vector<ListNode*> lists;
	for(int i = 0; i < 9; ++i)
		lists.push_back(new ListNode(i + 1));
	ListNode *rv = mergeKLists(lists);
	for(; rv != NULL; rv = rv->next)
		cout << rv->val << (rv->next ? "->" : "");
	cout << endl;
	return 1;
}
