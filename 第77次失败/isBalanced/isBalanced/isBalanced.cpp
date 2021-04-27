/*
剑指 Offer 55 - II. 平衡二叉树

输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

示例 1:
给定二叉树 [3,9,20,null,null,15,7]

	3
   / \
  9  20
	/  \
   15   7
返回 true 。

示例 2:
给定二叉树 [1,2,2,3,3,null,null,4,4]

	   1
	  / \
	 2   2
	/ \
   3   3
  / \
 4   4
返回 false 。

限制：
0 <= 树的结点个数 <= 10000
*/

/*
思路
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL){ }
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (getDepth(root->left) - getDepth(root->right) > 1 || getDepth(root->right) - getDepth(root->left) > 1) {
			return false;
		}
		return true;
	}

	//递归分别求每个根节点下左右子树高度，回调判断每个根节点是不是平衡的，那么需要实现计算深度的一个函数
	//第一步：确定参数与返回值：参数为传入根节点，就算需要左右节点值也可以用变量代替，返回值为高度差，如果已经不是平衡二叉树了，可以直接返回-1作为标记
	int getDepth(TreeNode* root) {
		//第二步：确定递归终止条件，root为空
		if (!root) {
			return 0;
		}
		//第三步，当前递归轮次需要做什么
		//这里就体现出思路差距了，这里是默认前面的处理没有任何问题了，前面的轮次结论是已知的
		int left_depth = getDepth(root->left);
		//如果已经是-1了，直接返回
		if (left_depth == -1) {
			return -1;
		}
		//右边同理
		int right_depth = getDepth(root->right);
		if (right_depth == -1) {
			return -1;
		}
		//如果之前轮次是平衡二叉树，那么求以当前节点为根节点子左右树的深度差
		int result;
		if (left_depth - right_depth > 1 || right_depth - left_depth > 1) {
			return -1;
		}
		else{
			//之前是平衡树，那么更新深度为当前节点+之前的深度
			result = 1 + max(left_depth, right_depth);
		}
		return result;
	}
};

int main() {
	Solution solu;

	//给定二叉树 [1,2,2,3,3,null,null,4,4]
	/*
		   1
	  / \
	 2   2
	/ \
   3   3
  / \
 4   4
	*/
	TreeNode* root = new TreeNode(1);
	TreeNode* _1_left = new TreeNode(2);
	TreeNode* _1_right = new TreeNode(2);
	TreeNode* _2_left_1 = new TreeNode(3);
	TreeNode* _2_left_2 = new TreeNode(3);
	TreeNode* _3_left_1 = new TreeNode(4);
	TreeNode* _3_left_2 = new TreeNode(4);

	root->left = _1_left;
	root->right = _1_right;
	_1_left->left = _2_left_1;
	_1_left->right = _2_left_2;
	_2_left_1->left = _3_left_1;
	_2_left_1->right = _3_left_2;

	if (solu.isBalanced(root)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
}
