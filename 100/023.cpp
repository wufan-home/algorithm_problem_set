/*
  Merge k sorted linked lists and return it as one sorted list. 
  Analyze and describe its complexity.
*/

ListNode *MergeTwoLists(ListNode *l, ListNode *r)
{
        ListNode *dummy = new ListNode(INT_MIN);
        for(ListNode *cur = dummy; l || r;)
        {
		ListNode* &moving = ((l ? l->val : INT_MAX) <= (r ? r->val : INT_MAX)) ? l : r;
		cur->next = moving;
		moving = moving->next;
		cur = cur->next;
        }
        return dummy->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists)
{
        for(int i = 1; i < lists.size(); i *= 2)
        {
		for(int j = 0; j + i < lists.size(); j += 2 * i)
			lists[j] = MergeTwoLists(lists[j], lists[j + i]);
        }
        return lists.empty() ? NULL : lists[0];
}

struct Compare
{
        bool operator() (const pair<ListNode *, int>& l, const pair<ListNode *, int>& r) const
        {
		return (l.first ? l.first->val : INT_MAX) > (r.first ? r.first->val : INT_MAX);
        }
};

ListNode* mergeKLists1(vector<ListNode*>& lists) 
{
        ListNode *dummy = new ListNode(INT_MIN);
        priority_queue<pair<ListNode *, int>, vector<pair<ListNode *, int> >, CompareClass> pq;
        for(int i = 0; i < lists.size(); ++i)
        {
		if(lists[i])
			pq.push(make_pair(lists[i], i));
        }

        for(ListNode *cur = dummy; !pq.empty(); cur = cur->next)
        {
		cur->next = pq.top().first;
		int index = pq.top().second;
		lists[index] = lists[index]->next;
		pq.pop();
		if(lists[index])
			pq.push(make_pair(lists[index], index));
        }
        return dummy->next;
}
