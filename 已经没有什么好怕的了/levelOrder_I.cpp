/*
Day2
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
#include <queue>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){ }
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == nullptr) {
			return { };
		}
		q.push(root); // 初始化
		while (!q.empty()) { // 退出条件是queue empty
			int sz = q.size(); // 这层节点个数，不直接用q.size作为判定条件
			vector<int> ret;
			for (int i = 0; i < sz; ++i) {
				TreeNode* node = q.front();
				q.pop();
				ret.push_back(node->val); // 更新结果
				if (node->left) q.push(node->left); // 压入左节点
				if (node->right) q.push(node->right); // 压入右节点
			}
			ans.push_back(ret);
		}
		return ans;
	}

private:
	queue<TreeNode*> q; // 存储每一层的节点
	vector<vector<int>> ans;
};


int main() {

}
