/*
剑指 Offer 55 - I. 二叉树的深度

输入一棵二叉树的根节点，求该树的深度。
从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

例如：
给定二叉树 [3,9,20,null,null,15,7]，

	3
   / \
  9  20
	/  \
   15   7

返回它的最大深度 3 。

提示：
节点总数 <= 10000
*/

/*
DFS初代

递归/栈
先使用递归实现
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
	//确定递归函数的参数和返回值：参数就是传入树的根节点，返回就返回这棵树的深度，所以返回值为int类型。
	int maxDepth(TreeNode* root) {
		//确定终止条件：如果为空节点的话，就返回0，表示高度为0。
		if (root == NULL) {
			return 0;
		}
		//确定单层递归的逻辑：先求左子树的深度，再求的右子树的深度，最后取左右深度最大的数值 再+1（算上当前中间节点）。
		int left_depth = maxDepth(root->left);
		int right_depth = maxDepth(root->right);
		int max_depth = max(left_depth, right_depth) + 1;
		return max_depth;
	}
};

int main() {
	//明天补一个建树的过程，可视化生成树，前序中序后序，搞懂他
}

