/*
Day2
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


class Solution_v1 {
public:
	int kthLargest(TreeNode* root, int k) {
		//最直观的想法是使用vector存值然后查找
		//利用二叉搜索树性质，中序遍历（左根右）为递增序列
		//这个中序遍历可以用迭代吗？
		vector<int> squence;
		midOrder(root, squence);
		int len = squence.size();
		return squence[len - k];
	}

	void midOrder(TreeNode* root, vector<int>& squence) {
		if (!root) {
			return;
		}
		midOrder(root->left, squence);
		squence.emplace_back(root->val);
		midOrder(root->right, squence);
	}
};

class Solution {
public:
	int kthLargest(TreeNode* root, int k) {
		//最直观的想法是使用vector存值然后查找
		//利用二叉搜索树性质，中序遍历（左根右）为递增序列
		//优化：倒序的中序遍历为递减序列
		antiMidOrder(root, k);
		return res;
	}

	void antiMidOrder(TreeNode* root, int& k) {
		if (!root || k == 0) {
			return;
		}
		antiMidOrder(root->right, k);
		--k;
		if (k == 0) {
			res = root->val;
		}
		antiMidOrder(root->left, k);
	}

private:
	int res;
};


int main() {

}
