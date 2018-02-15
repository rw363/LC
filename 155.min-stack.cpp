/*

 * [155] Min Stack

 *

 * https://leetcode.com/problems/min-stack/description/

 *

 * algorithms

 * Easy (30.57%)

 * Total Accepted:    170.7K

 * Total Submissions: 558.5K

 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'

 *

 * 

 * Design a stack that supports push, pop, top, and retrieving the minimum

 * element in constant time.

 * 

 * 

 * push(x) -- Push element x onto stack.

 * 

 * 

 * pop() -- Removes the element on top of the stack.

 * 

 * 

 * top() -- Get the top element.

 * 

 * 

 * getMin() -- Retrieve the minimum element in the stack.

 * 

 * 

 * 

 * 

 * Example:

 * 

 * MinStack minStack = new MinStack();

 * minStack.push(-2);

 * minStack.push(0);

 * minStack.push(-3);

 * minStack.getMin();   --> Returns -3.

 * minStack.pop();

 * minStack.top();      --> Returns 0.

 * minStack.getMin();   --> Returns -2.

 * 

 * 

 */

using namespace std;

class MinStack {
private:
     long min;
     stack<long> nums;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if (nums.empty())
        {
             min = x;
             nums.push(0L);
             return;
        }
        long val = x - min;
        nums.push(val);
        if (val < 0)
             min = x;
    }
    
    void pop() {
        long val = nums.top();
        nums.pop();
        if (val < 0)
             min -= val;
    }
    
    int top() {
        long val = nums.top();
        if (val <= 0)
             return min;
        return val + min;
    }
    
    int getMin() {
        return min;
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

