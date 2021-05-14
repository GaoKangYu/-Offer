/*
Day2
剑指 Offer 09. 用两个栈实现队列

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。
(若队列中没有元素，deleteHead 操作返回 -1 )

示例 1：
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]

示例 2：
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]

提示：
1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用
*/

/*
思路
*/

#include <iostream>
#include <stack>

using namespace std;

class CQueue {
public:
	CQueue() {
		cout << "[], ";
	}


	void appendTail(int value) {
		//实现头部删除和尾部插入
		//尾部插入好实现
		//需要一个栈始终维护头部元素
		tail.push(value);
		cout << "[], ";
	}

	int deleteHead() {
		//每次都把值倒出来然后再装回去？
		//这样的做法有可取之处，始终保持了full queue的值的完整
		//但是没必要啊
		//封装的思路
		//只需要完成当前需求
		if (!head.empty()) {
			int ret = head.top();
			head.pop();
			cout << "[" << ret << "], ";
			return ret;
		}
		else if (!tail.empty()) {
			while (!tail.empty()) {
				head.push(tail.top());
				tail.pop();
			}
			int ret = head.top();
			head.pop();
			cout << "[" << ret << "], ";
			return ret;
		}
		else {
			cout << "[" << -1 << "], ";
			return -1;
		}
	}

private:
	stack<int> head;
	stack<int> tail;
};

int main() {
	cout << "[";
	CQueue test;
	test.appendTail(1);
	test.appendTail(2);
	test.appendTail(3);
	test.appendTail(4);
	test.deleteHead();
	test.appendTail(5);
	test.deleteHead();
	test.deleteHead();
	test.deleteHead();
	test.deleteHead();
	test.deleteHead();
	test.deleteHead();
	cout << "]" << endl;
}
