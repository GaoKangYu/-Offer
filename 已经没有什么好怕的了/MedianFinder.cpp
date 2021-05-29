/*
Day2
剑指 Offer 41. 数据流中的中位数

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。

示例 1：
输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]

示例 2：
输入：
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
输出：[null,null,2.00000,null,2.50000]
 

限制：
最多会对 addNum、findMedian 进行 50000 次调用。
*/

/*
思路
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		max_q.push(num);
		min_q.push(max_q.top());
		max_q.pop();
		if (max_q.size() < min_q.size()) {
			max_q.push(min_q.top());
			min_q.pop();
		}
	}

	double findMedian() {
		return max_q.size() > min_q.size() ? max_q.top() * 1.0 : (max_q.top() + min_q.top()) * 0.5;
	}

private:
	priority_queue<int> max_q;
	priority_queue<int, vector<int>, greater<int> > min_q;
};

int main() {

}
