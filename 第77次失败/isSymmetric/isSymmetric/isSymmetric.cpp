/*
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
	TreeNode(int x): val(x), left(NULL), right(NULL){ }
};

class Solution {
public:
	//只想说，第77次失败，第154次失败，第308次失败
	bool isSymmetric(TreeNode* root) {
		//三步递归
		//第一步，确定返回值与传入参数，返回值直接bool就好，如果判断得到左右子树不相等，没必要再深入了，直接返回false就好，传入参数也只需要root
		//第二步，确定结束条件，root为空，返回true
		//第三步，确定在这一轮需要做什么，默认此前和之后轮次已经处理正确
		//此时我明确了那个问题，上下层的关系要怎么把握？
		//这里的问题是在于，这个问题好像不太能左右子树分开递归，因为镜像，需要比较左右子树下的左右子树是否对称
		//也就是需要比较，A节点左子树是否等于同一深度的B节点右子树
		//本质上还是思路变不过来，想象力不行
		//第一轮很简单，根节点左右子树是否相等，是就继续，否则直接false
		//但第二轮就不是对一个节点进行操作了，而是对两个节点，第三轮类似的则是对四个节点操作，这样下去递归就很难成立了
		//能否利用对称树的性质？
		//思路转变啊，包括不会做也不要过于自责，过于焦虑这样的思路
		if (!root) {
			return true;
		}
		return isSymmetric(root->left, root->right);
	}

	bool isSymmetric(TreeNode* left, TreeNode* right) {
		//如果左右子树都为空，那就说明一个单节点，是对称的
		if (left == NULL && right == NULL) {
			return true;
		}
		//左为空右不为，反之，则不是对称的
		else if ((left != NULL && right == NULL) || (left == NULL && right != NULL)) {
			return false;
		}
		//俩值不相等，返回false
		else if (left->val != right->val) {
			return false;
		}
		return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
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

	if (solu.isSymmetric(root)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
}
