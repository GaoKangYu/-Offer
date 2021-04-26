/*
剑指 Offer 68 - II. 二叉树的最近公共祖先

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：
“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

示例 1:
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。

示例 2:
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 
说明:
所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉树中。
*/

/*
好好思考一下
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL){ }
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//常规递归边界条件，root为空，目标节点p、q为空直接停止递归，如果某个目标节点直接是根节点了，说明公共祖先只可能是根节点，返回根节点
		if (!root || !p || !q || p == root || q == root) {
			return root;
		}

		TreeNode* leftTree = lowestCommonAncestor(root->left, p, q);//右子树递归，找两个目标节点
		TreeNode* rightTree = lowestCommonAncestor(root->right, p, q);

		if (!leftTree && !rightTree) {
			return nullptr; // 左边没找到右边也没找到，说明不存在这个公共祖先，返回空
		}
		else if (leftTree && rightTree) {
			return root; // 左边找到了右边也找到了，说明两个目标分别在左右子树，那么公共祖先是根节点
		}
		else if (!leftTree && rightTree) {
			return rightTree; // 左边没找到右边找到了，说明两个目标都在右子树，返回右子树
		}
		else {
			return leftTree; // 左边找到了右边没找到，说明两个目标都在左子树，返回左子树
		}
	}
};

int main() {
	//root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
	Solution solu;
	//新建节点
	TreeNode* root = new TreeNode(3);
	TreeNode* _1_left = new TreeNode(5);
	TreeNode* _1_right = new TreeNode(1);
	TreeNode* _2_left_1 = new TreeNode(6);
	TreeNode* _2_left_2 = new TreeNode(2);
	TreeNode* _2_right_1 = new TreeNode(0);
	TreeNode* _2_right_2 = new TreeNode(8);
	TreeNode* _3_left_3 = new TreeNode(7);
	TreeNode* _3_left_4 = new TreeNode(4);

	//串起来
	//3 5 1
	root->left = _1_left;
	root->right = _1_right;
	//5 6 2
	_1_left->left = _2_left_1;
	_1_left->right = _2_left_2;
	//2 7 4
	_2_left_2->left = _3_left_3;
	_2_left_2->right = _3_left_4;
	//1 0 8
	_1_right->left = _2_right_1;
	_1_right->right = _2_right_2;

	//p、q节点
	TreeNode* p = _1_left;
	TreeNode* q = _1_right;

	TreeNode* res = new TreeNode(0);
	res = solu.lowestCommonAncestor(root, p, q);
	if (res) {
		cout << "res : " << res->val << endl;
	}
	else{
		cout << "Null" << endl;
	}
}
