/*
  Merge k sorted linked lists and return it as one sorted list. 
  Analyze and describe its complexity.
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL;
        ListNode *cur = NULL;
        while(l1 || l2)
        {
            ListNode *nodeWithSmallerValue = l1 ? (l2 ? (l1->val <= l2->val ? l1 : l2) : l1) : (l2 ? l2 : NULL);
            
            if(nodeWithSmallerValue == l1)
                l1 = l1->next;
            else
                l2 = l2->next;
            
            if(head == NULL)
            {
                cur = nodeWithSmallerValue;
                head = cur;
            }
            else
            {
                cur->next = nodeWithSmallerValue;
                cur = cur->next;
            }
            
            cur->next = NULL;
        }
        
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        const int listSize = lists.size();
        for(int step = 1; step < listSize; step *= 2)
        {
            for(int i = 0; i + step < listSize; i += 2 * step)
                lists[i] = mergeTwoLists(lists[i], lists[i + step]);
        }
        
        return listSize > 0 ? lists[0] : NULL;
    }
};

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
