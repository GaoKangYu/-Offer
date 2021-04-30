/*
剑指 Offer 37. 序列化二叉树

请实现两个函数，分别用来序列化和反序列化二叉树。

示例: 

你可以将以下二叉树：

	1
   / \
  2   3
	 / \
	4   5

序列化为 "[1,2,3,null,null,4,5]"
*/

/*
思路
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL){ }
};

class Codec {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root)
	{
		string res = "";
		if (root == NULL)
			return "";
		queue<TreeNode*> Q;
		Q.push(root);
		while (!Q.empty())
		{
			TreeNode* p = Q.front();    Q.pop();
			if (p == NULL)
				res += "NULL,";
			else
			{
				res += to_string(p->val);   res += ',';
				Q.push(p->left);
				Q.push(p->right);
			}
		}

		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data)
	{
		vector<string> rec;

		if (data.size() == 0)
			return NULL;
		int i = 0, j = 0;
		while (i < data.size())
		{
			if (data[i] != ',')
				++i;
			else
			{
				string tmp = data.substr(j, i - j);
				rec.push_back(tmp);
				++i;
				j = i;
			}
		}
		if (j != i)
		{
			string tmp = data.substr(j, i - j);
			rec.push_back(tmp);
		}

		TreeNode * root = new TreeNode(stoi(rec[0]));
		queue<TreeNode*> Q;
		Q.push(root);
		i = 1;
		while (!Q.empty())
		{
			TreeNode* p = Q.front();    Q.pop();
			if (rec[i] != "NULL")
			{
				p->left = new TreeNode(stoi(rec[i]));
				Q.push(p->left);
			}
			++i;
			if (rec[i] != "NULL")
			{
				p->right = new TreeNode(stoi(rec[i]));
				Q.push(p->right);
			}
			++i;
		}
		return root;
	}
};

int main() {
	std::cout << "Hello World!\n";
}
