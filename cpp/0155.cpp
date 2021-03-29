/*
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.
    Example:
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin();   --> Returns -3.
    minStack.pop();
    minStack.top();      --> Returns 0.
    minStack.getMin();   --> Returns -2.
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        stackForElements.push(x);
        if(stackForLocalMinimalElementByIndex.empty() || x < stackForLocalMinimalElementByIndex.top().first)
            stackForLocalMinimalElementByIndex.push(make_pair(x, stackForElements.size()));
    }
    
    void pop() {
        stackForElements.pop();
        if(stackForElements.size() == stackForLocalMinimalElementByIndex.top().second - 1)
            stackForLocalMinimalElementByIndex.pop();
    }
    
    int top() {
        return stackForElements.top();
    }
    
    int getMin() {
        return stackForLocalMinimalElementByIndex.top().first;
    }
    
private:
    stack<int> stackForElements;
    stack<pair<int, int>> stackForLocalMinimalElementByIndex;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
