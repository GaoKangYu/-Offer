/*
783. 二叉搜索树节点最小距离

给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
*/

/*
行，想办法把二叉树玩明白
可视化
前序中序后序
多个题目

直觉上二叉树通常意味着递归

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int minDiffInBST(TreeNode* root) {
		vector<int> trans;
		transform(root, trans);
		//二叉搜索树中序遍历是递增数组
		int ret = INT_MAX;
		for (int i = 1; i <= trans.size() - 1; ++i) {
			ret = min(ret, trans[i] - trans[i - 1]);
		}
		return ret;
	}

	void transform(TreeNode* root, vector<int> &trans) {
		if (root == nullptr) {
			return;
		}
		//中序遍历，左，根，右
		transform(root->left, trans);
		trans.push_back(root->val);
		transform(root->right, trans);
	}
	//可视化，如果从根节点开始，对齐成了很大的问题、、好像是难题，先可视化指定样例的吧
	/*
	例如:
	给定二叉树: [3,9,20,null,null,15,7],
	3
   / \
  9  20
   	/  \
   15   7
	*/
	void show_tree(TreeNode* root) {
		for (int i = 0; i < 2; ++i) {
			printf(" ");
		}
		printf("%d\n", root->val);
		printf(" /");
		printf(" \\\n");
		printf("%d", root->left->val);
		printf("  %d\n",root->right->val);
		root = root->right;
		printf("  /");
		printf("  \\\n");
		printf(" %d", root->left->val);
		printf("  %d\n", root->right->val);
	}

	void show(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

	}
};

int main() {
	Solution solu;
	TreeNode* tree = new TreeNode;
	//{3,9,20,NULL,NULL,15,7};
	tree->val = 3;
	//熟悉的感觉
	//请你把节点的概念刻入DNA
	TreeNode* tree_left = new TreeNode;
	tree_left->val = 9;
	tree->left = tree_left;

	TreeNode* tree_right = new TreeNode;
	tree_right->val = 20;
	tree->right = tree_right;

	TreeNode* tree_right_left = new TreeNode;
	tree_right_left->val = 15;
	tree->right->left = tree_right_left;

	TreeNode* tree_right_right = new TreeNode;
	tree_right_right->val = 7;
	tree->right->right = tree_right_right;

	solu.show_tree(tree);
}

