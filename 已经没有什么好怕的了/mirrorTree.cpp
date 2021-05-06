/*
Day2
剑指 Offer 27. 二叉树的镜像

请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

 

示例 1：

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
 

限制：
0 <= 节点个数 <= 1000
*/

/*
学会递归
*/

#include <iostream>
#include <vector>

using namespace std;

//刻进DNA的struct
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(NULL), right(NULL){ }
	TreeNode(int x) : val(x), left(NULL), right(NULL){ }
};


class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		mirrorTreeProcess(root);
		return root;
	}

	//递归三部曲
	void mirrorTreeProcess(TreeNode* root) {
		//其一：终止条件是什么？——节点为空
		//因此递归常常需要返回值为void
		if (!root) {
			return;
		}
		if (!root->left && !root->right) {
			return;
		}
		//其二，默认前后处理完全正确，只需要专注于这一层的操作
		//这一层需要进行什么样的操作？——交换左右子树
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		//其三，继续递归
		//如果左子树不为空，递归左边
		if (root->right) {
			mirrorTreeProcess(root->right);
		}
		//如果右子树不为空，递归右边
		if (root->left) {
			mirrorTreeProcess(root->left);
		}
	}

	void showTree(TreeNode* root) {
		if (!root) {
			return;
		}
		//前序遍历
		cout << root->val << " ";
		showTree(root->left);
		showTree(root->right);
	}
};

int main() {
	Solution solu;
	//[4,2,7,1,3,6,9]
	TreeNode* root = new TreeNode(4);
	TreeNode* _1_left = new TreeNode(2);
	TreeNode* _1_right = new TreeNode(7);
	TreeNode* _2_1_left_left = new TreeNode(1);
	TreeNode* _2_1_left_right = new TreeNode(3);
	TreeNode* _2_1_right_left = new TreeNode(6);
	TreeNode* _2_1_right_right = new TreeNode(9);

	root->left = _1_left;
	root->right = _1_right;
	_1_left->left = _2_1_left_left;
	_1_left->right = _2_1_left_right;
	_1_right->left = _2_1_right_left;
	_1_right->right = _2_1_right_right;
	cout << "Input : [";
	solu.showTree(root);
	cout << "]" <<endl;
	solu.mirrorTree(root);
	cout << "Output : [";
	solu.showTree(root);
	cout << "]" << endl;
}
