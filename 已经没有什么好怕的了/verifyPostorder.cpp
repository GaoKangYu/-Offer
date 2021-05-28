/*
Day2
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
二叉搜索树中序遍历为递增序列

左中右为递增序列

后序遍历为左右中

感觉还是一个模拟建树过程
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		if (postorder.empty()) {
			return true;
		}
		bool res = verifyPostorderProcess(postorder, 0, postorder.size() - 1);
		return res;
	}

	bool verifyPostorderProcess(vector<int>& postorder, int start, int end) {
		//后序遍历，最后一个值为根节点，左子树的值都小于根节点，右子树的值都大于根节点
		//同样的，左子树的根节点，右子树的根节点也满足这个性质，使用递归即可s
		if (start >= end) {
			return true;
		}
		//首先是找到根节点
		int root_val = postorder[end];
		int i = start;
		//小于根节点值的属于左子树
		while (postorder[i] < root_val) {
			++i;
		}
		int left_end = i - 1;
		//至此左子树遍历结束
		//开始右子树遍历
		while (postorder[i] > root_val) {
			++i;
		}
		//右子树应该刚好结束在right-1处
		return i == end && (verifyPostorderProcess(postorder, start, left_end) && verifyPostorderProcess(postorder, left_end + 1, end - 1));
	}
};



int main() {

}
