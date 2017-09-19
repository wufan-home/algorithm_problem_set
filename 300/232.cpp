/*
    Implement the following operations of a queue using stacks.

    push(x) -- Push element x to the back of queue.
    pop() -- Removes the element from in front of queue.
    peek() -- Get the front element.
    empty() -- Return whether the queue is empty.
    Notes:
    You must use only standard operations of a stack -- 
    which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, stack may not be supported natively. 
    You may simulate a stack by using a list or deque (double-ended queue), 
    as long as you use only standard operations of a stack.
    You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

class Queue {
public:
    #include <stack>
    // Push element x to the back of queue.
    void push(int x) {
        if(m_stack.empty()) {
            while(!m_stack_backup.empty()) {
                m_stack.push(m_stack_backup.top());
                m_stack_backup.pop();
            }
        }
        m_stack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(m_stack_backup.empty()) {
            while(!m_stack.empty()) {
                m_stack_backup.push(m_stack.top());
                m_stack.pop();
            }
        }
        m_stack_backup.pop();
    }

    // Get the front element.
    int peek(void) {
        if(m_stack_backup.empty()) {
            while(!m_stack.empty()) {
                m_stack_backup.push(m_stack.top());
                m_stack.pop();
            }
        }
        return m_stack_backup.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (m_stack.empty() && m_stack_backup.empty());
    }
    
private:
    stack<int> m_stack;
    stack<int> m_stack_backup;
};
