/*
Day2
剑指 Offer 68 - I. 二叉搜索树的最近公共祖先

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){ }
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//二叉搜索树性质：中序遍历为递增序列
		//最朴素的想法，如果两个都在左子树，搜索左子树
		//如果一个在左一个在右，返回根节点
		//如果都在右，搜索右子树
		while (root) {
			//如果两个节点有一个是根节点，返回根节点
			if (p->val == root->val || q->val == root->val) {
				return root;
			}
			//如果两个都比根节点大，那么肯定都在根节点右侧
			else if (p->val > root->val && q->val > root->val) {
				root = root->right;
			}
			//如果两个都比根节点小，那么肯定都在根节点左侧
			else if (p->val < root->val && q->val < root->val) {
				root = root->left;
			}
			//否则，一大一小，肯定分布在两边
			else {
				return root;
			}
		}
		return NULL;
	}
};

int main() {
	Solution solu;

	//root = [6,2,8,0,4,7,9,null,null,3,5]
	TreeNode* root = new TreeNode(6);
	TreeNode* _1_left = new TreeNode(2);
	TreeNode* _1_right = new TreeNode(8);
	TreeNode* _2_1_left_left = new TreeNode(0);
	TreeNode* _2_1_left_right = new TreeNode(4);
	TreeNode* _2_1_right_left = new TreeNode(7);
	TreeNode* _2_1_right_right = new TreeNode(9);
	TreeNode* _3_2_1_left_left = new TreeNode(3);
	TreeNode* _3_2_1_left_right = new TreeNode(5);

	root->left = _1_left;
	root->right = _1_right;
	_1_left->left = _2_1_left_left;
	_1_left->right = _2_1_left_right;
	_1_right->left = _2_1_right_left;
	_1_right->right = _2_1_right_right;
	_2_1_left_right->left = _3_2_1_left_left;
	_2_1_left_right->right = _3_2_1_left_right;

	TreeNode* p = _1_left;
	TreeNode* q = _3_2_1_left_right;

	TreeNode* res = solu.lowestCommonAncestor(root, p, q);
	cout << "Res : " << res->val << endl;
}
