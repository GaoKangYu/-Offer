/*
剑指 Offer 32 - I. 从上到下打印二叉树

从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

例如:
给定二叉树: [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7

返回：
[3,9,20,15,7]
 
提示：
节点总数 <= 1000
*/

/*
层序遍历需要借助队列

如果节点不为空
节点入队
队首值压入返回数组，节点出队
如果有左右子树
左子树入队
右子树入队

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() { }
	TreeNode(int x): val(x), left(NULL), right(NULL){ }
};

class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		vector<int> res;

		// 考虑边缘情况
		if (root != nullptr) {
			q.push(root);
		}
		// 一直遍历直到队列里为空
		while (!q.empty()) {
			TreeNode* curr = q.front();
			q.pop();
			res.push_back(curr->val);
			if (curr->left != nullptr) {
				q.push(curr->left);
			}
			if (curr->right != nullptr) {
				q.push(curr->right);
			}
		}
		return res;
	}
};

int main() {
	Solution solu;

	TreeNode* root = new TreeNode(1);
	TreeNode* _1_left = new TreeNode(2);
	TreeNode* _1_right = new TreeNode(3);
	TreeNode* _2_left_1 = new TreeNode(4);
	TreeNode* _2_left_2 = new TreeNode(5);

	root->left = _1_left;
	root->right = _1_right;
	_1_left->left = _2_left_1;
	_1_left->right = _2_left_2;

	vector<int> res = solu.levelOrder(root);
	cout << "[";
	for (auto n : res){
		cout << n << " ";
	}
	cout << "]" << endl;
}
