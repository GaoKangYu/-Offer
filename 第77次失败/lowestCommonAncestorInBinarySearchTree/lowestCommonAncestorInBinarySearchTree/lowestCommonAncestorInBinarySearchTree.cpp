/*
剑指 Offer 68 - I. 二叉搜索树的最近公共祖先

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：
“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

示例 1:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6
解释: 节点 2 和节点 8 的最近公共祖先是 6。
示例 2:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 
说明:
所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉搜索树中。
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
	TreeNode(int x) : val(x), left(NULL), right(NULL) { };
};

class Solution {
public:
	TreeNode* lowestCommonAncestor_normal(TreeNode* root, TreeNode* p, TreeNode* q) {
		//照猫画虎
		//这个题目应该是可以借助二叉搜索树的条件节省迭代次数的
		//搜索树的特性为：中序遍历为递增序列
		//先写通用方法
		if (!root || !p || !q || p == root || q == root) {
			return root;
		}
		TreeNode* leftTree = lowestCommonAncestor(root->left, p, q);
		TreeNode* rightTree = lowestCommonAncestor(root->right, p, q);
		
		//如果左右子树都没有，那么没有找到目标节点，返回空
		if (!leftTree && !rightTree) {
			return NULL;
		}
		//如果左右子树都有，那么目标节点分布在左右子树，返回根节点
		else if (leftTree && rightTree){
			return root;
		}
		//如果左子树有右子树没有，目标节点在左子树，返回左子树
		else if (leftTree && !rightTree) {
			return leftTree;
		}
		else{
			return rightTree;
		}
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//利用性质
		//如果根节点值与pq中任一值相等，直接返回根节点
		//如果pq都比根节点值大，那么搜索右子树
		//如果都比根节点小，那么搜索左子树
		//如果一个大一个小，也返回根节点
		//迭代法
		while (root){
			if (p->val > root->val && q->val > root->val) {
				root = root->right;
			}
			else if(p->val < root->val && q->val < root->val){
				root = root->left;
			}
			else{
				return root;
			}
		}
		return NULL;
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
	else {
		cout << "Null" << endl;
	}
}
