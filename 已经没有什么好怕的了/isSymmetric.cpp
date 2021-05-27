/*
Day2
剑指 Offer 28. 对称的二叉树

请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

 

示例 1：
输入：root = [1,2,2,3,4,4,3]
输出：true

示例 2：
输入：root = [1,2,2,null,3,null,3]
输出：false 

限制：
0 <= 节点个数 <= 1000
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
	bool isSymmetric(TreeNode* root) {
		//递归的方法？
		//本质上需要两个指针
		if (!root) {
			return true;
		}
		return isSymmetricProcess(root->left, root->right);
	}

	bool isSymmetricProcess(TreeNode* left, TreeNode* right) {
		//如果左右子树都是空的，那么说明是单节点，是对称的
		if (left == NULL && right == NULL) {
			return true;
		}
		//左空右不空，右空左不空，不对称
		else if ((left == NULL && right) || (left && right == NULL)) {
			return false;
		}
		//左右值不等，不对称
		else if (left->val != right->val) {
			return false;
		}
		return isSymmetricProcess(left->left, right->right) && isSymmetricProcess(left->right, right->left);
	}

};

int main() {

}
