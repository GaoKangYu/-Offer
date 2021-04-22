/*
剑指 Offer 31. 栈的压入、弹出序列

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

示例 1：
输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

示例 2：
输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。 

提示：
0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed 是 popped 的排列。
*/

/*
大概懂了题目的意思

没太大必要建栈，核心是相邻元素的进出顺序，4个指针，比较先后顺序
但这个判断条件太强了一些，还需要在出栈队列中找一个判断值
1可以在2之前出栈吗？可以，只要2不在栈里，压入1，出1，压入1，压入2，出2，就可以实现先出1再出2，所以如果2在栈里，就无法进行这一步
4可以在5之前出栈吗？可以，只要5不在栈里
抽象一下，出栈元素在其栈前元素不在栈里的时候，可以先于栈前元素出栈
所以可以优化的点之一：第一个出栈元素可以不用管，怎么都可以实现  done
另外：咋感觉可以动态规划。。

怎么知道2或者5在不在栈里？看上一步，如果5出栈，说明此时4必然在

模拟
模拟
最近这状态。。。。

直接照着出栈对列行不行就行啊
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> push;
		//模拟
		int i = 0;
		for (auto p : pushed) {
			push.push(p);
			while (push.size() && push.top() == popped[i]) {
				push.pop();
				++i;
			}
		}
		return !push.size();
	}

	void acm() {
		int test_nums;
		cin >> test_nums;
		while (test_nums){
			vector<int> pushed;
			int tmp_1;
			while (cin >> tmp_1){
				pushed.push_back(tmp_1);
				if (getchar() == '\n') {
					break;
				}
			}
			vector<int> popped;
			int tmp_2;
			while (cin >> tmp_2) {
				popped.push_back(tmp_2);
				if (getchar() == '\n') {
					break;
				}
			}
			if (validateStackSequences(pushed, popped)) {
				cout << "True" << endl;
			}
			else {
				cout << "Fasle" << endl;
			}
			--test_nums;
		}
	}
};

int main() {
	Solution solu;
	solu.acm();
}
