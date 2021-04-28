/*
剑指 Offer 32 - III. 从上到下打印二叉树 III

请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

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
  [20,9],
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
	TreeNode(){ }
	TreeNode(int x): val(x), left(NULL), right(NULL){ }
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr)
		{
			return res;
		}
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			vector<int> currs;
			for (int i = q.size() - 1; i >= 0; --i)
			{
				TreeNode* curr = q.front();
				q.pop();
				currs.push_back(curr->val);
				if (curr->left)
				{
					q.push(curr->left);
				}
				if (curr->right)
				{
					q.push(curr->right);
				}
			}
			// 当前res.size()为偶数时无需翻转，否则要翻转
			if (res.size() & 1)
			{
				reverse(currs.begin(), currs.end());
			}
			res.push_back(currs);
		}

		return res;
	}
};


int main() {
	std::cout << "Hello World!\n";
}
