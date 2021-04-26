/*
剑指 Offer 32 - II. 从上到下打印二叉树 II

从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

例如:
给定二叉树: [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
 
提示：
节点总数 <= 1000
*/

/*
思路
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		dfs(root, res, 0);
		return res;
	}
	void dfs(TreeNode* root, vector<vector<int>>& res, int level){
		if (!root) {
			return;
		}
		if (level >= res.size()) {
			res.emplace_back(vector<int>());
		}
		res[level].emplace_back(root->val);
		dfs(root->left, res, level + 1);
		dfs(root->right, res, level + 1);
	}
};

int main() {
	Solution solu;
	/*
		3
   / \
  9  20
	/  \
   15   7
	*/
	TreeNode* root = new TreeNode(3);
	TreeNode* _1_left = new TreeNode(9);
	TreeNode* _1_right = new TreeNode(20);
	TreeNode* _2_right_left = new TreeNode(15);
	TreeNode* _2_right_right = new TreeNode(7);

	root->left = _1_left;
	root->right = _1_right;
	_1_right->left = _2_right_left;
	_1_right->right = _2_right_right;
	cout << "[" << endl;
	for (auto vec : solu.levelOrder(root)){
		cout << "[";
		for (int i = 0; i < vec.size(); ++i){
			cout << vec[i];
			if (i < vec.size() - 1) {
				cout << ",";
			}

		}
		cout << "]" << endl;
	}
	cout << "]" << endl;
}
