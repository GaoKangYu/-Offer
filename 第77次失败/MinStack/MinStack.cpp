/*
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
	int push_count = 0;
	int pop_count = 0;
	int top_count = 0;
	int min_count = 0;
	/** initialize your data structure here. */
	//两个栈，一个正常进出，一个维护最小值
	stack<int> normal_stack;
	stack<int> min_val;
	MinStack() {
		cout << "[null";
	}

	void push(int x) {
		//每次压入元素的时候，普通栈正常压入
		normal_stack.push(x);
		//最小栈仅在空栈或者压入元素比栈顶的值小的时候压入
		if (min_val.empty() || x <= min_val.top()){
			min_val.push(x);
		}
		cout << ",null";
	}

	void pop() {
		//每次取出元素时，普通栈正常取出
		int pop_val = normal_stack.top();
		normal_stack.pop();
		//如果取出的这个值和最小栈顶值相等，把最小栈顶值取出
		if (pop_val == min_val.top()) {
			min_val.pop();
		}
		cout << ",null";
	}

	int top() {
		//查看栈顶值
		cout << "," << normal_stack.top();
		return normal_stack.top();
	}

	int min() {
		//查看最小值
		cout << "," << min_val.top();
		return min_val.top();
	}
};

int main() {
	//尝试一下acm
	MinStack* min_stack = new MinStack();
	min_stack->push(-2);
	min_stack->push(0);
	min_stack->push(-3);
	min_stack->min();
	min_stack->pop();
	min_stack->top();
	min_stack->min();
	cout << "]" << endl;
}
