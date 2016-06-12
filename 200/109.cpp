/*
  Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

#include <iostream>
#include <climits>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

TreeNode *build(ListNode *head, int count)
{	
	int left = count / 2;
	ListNode *lend = head;
	for(int i = 0; i < left; ++i, lend = lend->next) {}
	TreeNode *root = new TreeNode(lend->next->val);
	if(left)
		root->left = build(head, left);
	if(count - left - 1)
		root->right = build(lend->next, count - left - 1);
	return root;
}

TreeNode* sortedListToBST(ListNode* head) {
	if(head == NULL)
		return NULL;

	int count = 0;
	for(ListNode *cur = head; cur != NULL; cur = cur->next, ++count) {}

	ListNode *dummy = new ListNode(INT_MIN);
	dummy->next = head;

	return build(dummy, count);
}

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *cur = head;
	for(int i = 2; i <= 7;++i, cur = cur->next)
		cur->next = new ListNode(i);

	TreeNode *root = sortedListToBST(head);
	
	queue<TreeNode *> node_queue;
	node_queue.push(root);
	int level = node_queue.size();
	while(!node_queue.empty())
	{
		TreeNode *cur = node_queue.front();
		node_queue.pop();
		--level;
		cout << cur->val << ", ";
		if(cur->left)
			node_queue.push(cur->left);
		if(cur->right)
			node_queue.push(cur->right);
		if(level == 0)
		{
			level = node_queue.size();
			cout << endl;
		}
	}

	return 1;
}
