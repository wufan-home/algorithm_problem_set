/*
  Given a linked list, determine if it has a cycle in it.
  Follow up:
  Can you solve it without using extra space?
*/

bool hasCycle(ListNode *head) {
        if(head == NULL)
    		return false;
    
    	ListNode *slow = head;
    	ListNode *fast = head;
    	do
    	{
    		slow = slow->next;
    		fast = fast->next;
    		if(fast)
    			fast = fast->next;
    	}while(slow && fast && slow != fast);

    	return slow != NULL && fast != NULL;
}
