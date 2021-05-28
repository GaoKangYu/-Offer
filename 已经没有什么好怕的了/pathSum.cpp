/*
Day2
题目描述
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
	vector<vector<int>> pathSum(TreeNode* root, int target) {
		dfs(root, target);
		return ret;
	}

	void dfs(TreeNode* root, int target) {
		if (!root) {
			return;
		}
		path.emplace_back(root->val);
		target -= root->val;
		if (!root->left && !root->right && !target) {
			ret.emplace_back(path);
		}
		dfs(root->left, target);
		dfs(root->right, target);
		path.pop_back();
	}

private:
	vector<vector<int> > ret;
	vector<int> path;
};

int main() {

}
