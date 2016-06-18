/*
  Remove all elements from a linked list of integers that have value val.
  Example
  Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
  Return: 1 --> 2 --> 3 --> 4 --> 5
*/


ListNode* removeElements(ListNode* head, int val) {
	ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        for(ListNode *cur = dummy; cur->next;)
        {
            if(cur->next->val == val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        
        return dummy->next;
}
