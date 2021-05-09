/*
Day2
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
思路
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		vector<int> ret;
		queue<TreeNode*> q;
		if (!root) {
			return ret;
		}
		q.push(root);
		while (!q.empty()) {
			TreeNode* cur = q.front();
			ret.push_back(cur->val);
			//其实核心就在于这里，单纯递归很难去除这个重复根节点
			q.pop();
			if (cur->left) {
				q.push(cur->left);
			}
			if (cur->right) {
				q.push(cur->right);
			}
		}
		return ret;
	}
};

int main() {
	Solution solu;
	// 3 9 20 null null 15 7
	TreeNode* root = new TreeNode(3);
	TreeNode* _1_left = new TreeNode(9);
	TreeNode* _1_right = new TreeNode(20);
	TreeNode* _2_1_right_left = new TreeNode(15);
	TreeNode* _2_1_right_right = new TreeNode(7);

	root->left = _1_left;
	root->right = _1_right;
	_1_right->left = _2_1_right_left;
	_1_right->right = _2_1_right_right;

	vector<int> res = solu.levelOrder(root);
	cout << "[";
	for (auto n : res) {
		cout << n << " ";
	}
	cout << "]" << endl;
}
