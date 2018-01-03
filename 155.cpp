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


// GentleSpoon me@gentlespoon.com
// Leetcode    Q155
// Start       2018-01-02-20-52-06
// Finish      2018-01-02-21-05-09



class MinStack {
public:
    stack<int> all;
    stack<int> min; // sorted stack with the top() as the smallest int

    MinStack() {
        
    }
    
    void push(int x) {
        if (min.empty()) {
            min.push(x);
        } else {
            if (x <= min.top()) { // if the same as the smallest int, push again
                min.push(x);
            }
        }
        all.push(x);
    }

    void pop() {
        if (all.top() == min.top()) { // if smallest, pop from min stack
            min.pop();
        }
        all.pop();
    }

    int top() {
        return all.top();
    }

    int getMin() {
        return min.top();
    }                                  
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */