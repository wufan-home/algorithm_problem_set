/*
  Given a linked list, remove the nth node from the end of list and return its head.
  For example,
  Given linked list: 1->2->3->4->5, and n = 2.
  After removing the second node from the end, the linked list becomes 1->2->3->5.
  Note:
  Given n will always be valid.
  Try to do this in one pass.
  
  Solution: This problem is a good practice for counting elements backward.
  By the indexing method in languages, index starts from 0 when to read an element from an array.
  This means that the indices set is like {0, 1, ..., m - 1}.
  From the backwark, the indices set is like {m - m, m - (m - 1), ..., m - 1}. 
  In other word, the backward counting starts from 1 but not 0.
  Then, in this problem, if it removes the n-th element backward, 
  it just means to remove the n-th, but not the (n - 1)-th, element starting from the end of the linked list.
  
  The basic idea of this problem is that: set up two pointers, one front and one back; 
  keep the distance of the two pointers not changed, 
  i.e., the number of nodes between two pointers are nothing but (n - 1) consecutive nodes; 
  always remove the next node of the back pointer.
  
  Based on this algorithm, 
  we should stop the front pointer when it points to the last node of the list but not the NULL token.
  Delete a NULL token is meaningless.
  
  To avoid using a dummy node, we have a branch to deal with the coner case, 
  that is when n is the number of elements of the linked list.
  In this case, we should remove the node itself but not the next one as normal cases.
  This is equivelant to have a pre-head and remove the next node of the pre-head.  
 */

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *front = head;
        for(int i = 0; i < n; ++i)
            front = front->next;
            
        if(front == NULL)
        {
            ListNode *node_to_delete = head;
            head = head->next;
            delete node_to_delete;
        }
        else
        {
            ListNode *back = head;
            for(; front->next != NULL; front = front->next)
                back = back->next;
                
            ListNode *node_to_delete = back->next;
            back->next = back->next->next;
            delete node_to_delete;
        }

        return head;
    }
