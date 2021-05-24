/*
Day2
剑指 Offer 30. 包含min函数的栈

定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。


示例:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
 

提示：
各函数的调用总次数不超过 20000 次
*/

/*
思路
*/

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	//用一个两个常规栈
	stack<int> st;
	stack<int> min_stack;
	MinStack() {

	}

	void push(int x) {
		st.push(x);
		if (min_stack.empty() || x <= min_stack.top()) {
			min_stack.push(x);
		}
	}

	void pop() {
		int pop_val = st.top();
		st.pop();
		if (min_stack.top() == pop_val) {
			min_stack.pop();
		}

	}

	int top() {
		return st.top();
	}

	int min() {
		return min_stack.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main() {

}
