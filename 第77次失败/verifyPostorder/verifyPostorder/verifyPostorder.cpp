/*
剑指 Offer 33. 二叉搜索树的后序遍历序列

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。

如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

 
参考以下这颗二叉搜索树：

	 5
	/ \
   2   6
  / \
 1   3

示例 1：
输入: [1,6,3,2,5]
输出: false

示例 2：
输入: [1,3,2,6,5]
输出: true
 

提示：
数组长度 <= 1000
*/

/*
通常这样的题目会是模拟数据结构的做法

二叉搜索树的性质：中序遍历为递增序列

中序为左中右
题设为后序，左右中
如果说模拟，那就是用后序建树
不会呀

中序：小中大
后序：小大中
后序反转：中大小

那么从末尾到开头进行遍历，需要满足中大小这个条件，使用单调栈完成
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		if (postorder.size() == 0) {
			return true;
		}
		stack<int> q;
		int root = INT_MAX;
		//输入: [1,3,2,6,5]
		//根右左
		for (int i = postorder.size() - 1; i >= 0; i--) {
			if (postorder[i] > root) {
				return false;
			}
			while (!q.empty() && q.top() > postorder[i]) {
				root = q.top();
				q.pop();
			}
			q.push(postorder[i]);
		}
		return true;
	}
};

int main() {
	Solution solu;
	vector<int> input{ 1,21,32,11,4,12,4,6 };
	if (solu.verifyPostorder(input)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
}
