/*
Day2
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


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		//难点在于判断奇偶行，奇数从左到右，偶数从右到左
		if (!root) {
			return {};
		}
		q.push(root);
		while (!q.empty()) {
			vector<int> tmp;
			for (int i = q.size() - 1; i >= 0; --i) {
				TreeNode* cur = q.front();
				q.pop();
				tmp.emplace_back(cur->val);
				if (cur->left) {
					q.push(cur->left);
				}
				if (cur->right) {
					q.push(cur->right);
				}
			}
			//每次为下次push到tmp做好了准备，所以实际上的奇偶是错位的
			if (ret.size() % 2 != 0) {
				reverse(tmp.begin(), tmp.end());
			}
			ret.emplace_back(tmp);
		}
		return ret;
	}

private:
	vector<vector<int> > ret;
	queue<TreeNode*> q;
};

int main() {

}
