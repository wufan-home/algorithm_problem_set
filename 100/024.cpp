/*
  Given a linked list, swap every two adjacent nodes and return its head.
  For example,
  Given 1->2->3->4, you should return the list as 2->1->4->3.
  Your algorithm should use only constant space. 
  You may not modify the values in the list, only nodes itself can be changed.
*/

ListNode* swapPairs(ListNode* head)
{
            ListNode *dummy = new ListNode(INT_MIN);
            ListNode *ncur = dummy;
            for(ListNode *ocur = head; head != NULL; ocur = head)
            {
		    head = head->next;
		    if(head) 
			    head = head->next;
                    
		    if(ocur->next)
		    {
			    ncur->next = ocur->next;
			    ncur = ncur->next;
		    }
                
		    ncur->next = ocur;
		    ncur = ncur->next;
            }
            ncur->next = NULL;
            return dummy->next;
}
