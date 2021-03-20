/*
CQueue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

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
两个栈实现队列
栈的功能：.push  .pop   .top
appendTail用push即可
deleteHead如何实现？
一个栈维护队头，一个栈维护正序队列？
一个逆序一个正序？

还是说一个加，另一个辅助删
那岂不是每次删的时候都要把前者全取出来

改进:不用每次都恢复queue_full，保有queue_head即可
*/
class CQueue {
public:
	stack<int> queue_head;
	stack<int> queue_full;
	CQueue() {
	}

	void appendTail(int value) {
		queue_full.push(value);
	}

	int deleteHead() {
		int ret;
		if (!queue_head.empty()) {
			ret = queue_head.top();
			queue_head.pop();
			return ret;
		}
		else if (!queue_full.empty()) {
			while (!queue_full.empty()) {
				queue_head.push(queue_full.top());
				queue_full.pop();
			}
			ret = queue_head.top();
			queue_head.pop();
			return ret;
		}
		else {
			return -1;
		}
	}
};
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
