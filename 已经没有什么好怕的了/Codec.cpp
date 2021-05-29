/*
Day2
题目描述
*/

/*
思路
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){ }
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		//序列化是层序遍历，慢慢来吧
		//层序遍历需要queue
		q.push(root);
		while (!q.empty()) {
			TreeNode* cur = q.front();
			q.pop();
			if (cur) {
				out << cur->val << " ";
				q.push(cur->left);
				q.push(cur->right);
			}
			else {
				out << "null ";
			}
		}
		return out.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream input(data);
		string val;
		vector<TreeNode*> vec;
		while (input >> val) {
			if (val == "null") {
				vec.push_back(NULL);
			}
			else {
				vec.push_back(new TreeNode(stoi(val)));
			}
		}
		//至此将输入流的节点数据读入了vec中
		int j = 1;
		for (int i = 0; j < vec.size(); ++i) {
			if (vec[i] == NULL) continue;
			if (j < vec.size()) {
				vec[i]->left = vec[j++];
			}
			if (j < vec.size()) {
				vec[i]->right = vec[j++];
			}
		}
		return vec[0];
	}

private:
	queue<TreeNode*> q;
	ostringstream out;
	istringstream in;
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


int main() {

}
