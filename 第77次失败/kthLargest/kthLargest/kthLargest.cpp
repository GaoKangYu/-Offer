/*
剑指 Offer 54. 二叉搜索树的第k大节点

给定一棵二叉搜索树，请找出其中第k大的节点。

 

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
	   5
	  / \
	 3   6
	/ \
   2   4
  /
 1
输出: 4
 

限制：

1 ≤ k ≤ 二叉搜索树元素个数
*/

/*
二叉搜索树：特点印象中是左子树最小根节点次之右子树最大
那么，需要找第K大的节点值，遍历方式可以改成右中左
尝试一下，递归的写法

记住定义，二叉搜索树的中序遍历为递增序列，中序遍历为左中右
那么如果把这个序列记录下来，第K大的值就是倒数第K个数，或者直接中序遍历反着来，右中左，就变成顺序的K
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
	int res;
	int kthLargest(TreeNode* root, int k) {
		dfs(root, k);
		return res;
	}

	void dfs(TreeNode* root, int& k) {
		if (!root) {
			return;
		}
		//倒序的中序遍历，右
		dfs(root->right, k);
		--k;
		//中
		if (k == 0) {
			res = root->val;
		}
		//左
		dfs(root->left, k);
	}
};

int main() {
	Solution solu;
	//root = [5,3,6,2,4,null,null,1], k = 3
	/*
		   5
	  / \
	 3   6
	/ \
   2   4
  /
 1
输出: 4
	*/
	TreeNode* root = new TreeNode(5);
	TreeNode* left_1 = new TreeNode(3);
	TreeNode* right_1 = new TreeNode(6);
	TreeNode* left_2 = new TreeNode(2);
	TreeNode* right_2 = new TreeNode(4);
	TreeNode* left_3 = new TreeNode(1);

	root->left = left_1;
	root->right = right_1;

	left_1->left = left_2;
	left_1->right = right_2;

	left_2->left = left_3;

	cout << solu.kthLargest(root, 3) << endl;
}
